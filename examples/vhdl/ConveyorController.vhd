
-- This file has been automatically generated by go-iec61499-vhdl and should not be edited by hand
-- Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499-vhdl

-- This file represents the Basic Function Block for ConveyorController

library ieee;
use ieee.std_logic_1164.all;


entity ConveyorController is

	port(
		--for clock and reset signal
		clk		: in	std_logic;
		reset	: in	std_logic;
		enable	: in	std_logic;
		
		--input events
		InjectDone : in std_logic;
		EmergencyStopChanged : in std_logic;
		LasersChanged : in std_logic;
		
		
		--output events
		ConveyorChanged : out std_logic;
		ConveyorStoppedForInject : out std_logic;
		
		
		--input variables
		EmergencyStop : in std_logic; --type was BOOL
		InjectSiteLaser : in std_logic; --type was BOOL
		
		
		--output variables
		ConveyorSpeed : out std_logic_vector(7 downto 0); --type was BYTE
		
		--for done signal
		done : out std_logic
	);

end entity;


architecture rtl of ConveyorController is
	
	-- Build an enumerated type for the state machine
	type state_type is (E_Stop, Running, Pause);

	-- Register to hold the current state
	signal state   : state_type := E_Stop;

	-- signals for enabling algorithms	
	signal ConveyorStart_alg_en : std_logic := '0'; 
	signal ConveyorStart_alg_done : std_logic := '1';
	
	signal ConveyorStop_alg_en : std_logic := '0'; 
	signal ConveyorStop_alg_done : std_logic := '1';
	
	signal ConveyorRunning_alg_en : std_logic := '0'; 
	signal ConveyorRunning_alg_done : std_logic := '1';
	
	signal ConveyorEStop_alg_en : std_logic := '0'; 
	signal ConveyorEStop_alg_done : std_logic := '1';
	

	-- signal for algorithm completion
	signal AlgorithmsStart : std_logic := '0';
	signal AlgorithmsDone : std_logic;

	--internal variables 
	signal Variable1 : std_logic; --type was BOOL 
begin
	
	-- Logic to advance to the next state
	process (clk, reset)
	begin
		if reset = '1' then
			state <= E_Stop;
			AlgorithmsStart <= '1';
		elsif (rising_edge(clk)) then
			if AlgorithmsStart = '1' then --algorithms should be triggered only once via this pulse signal
				AlgorithmsStart <= '0'
			elsif enable = '1' then 
				--default values
				state <= state;
				AlgorithmsStart <= '0';

				--next state logic
				elsif AlgorithmsStart = '0' and AlgorithmsDone = '1' then
					case state is
						when E_Stop=>
							if EmergencyStopChanged = '1' and (not EmergencyStop = '1') then
								state <= Running;
								AlgorithmsStart <= '1';
							end if;
						when Running=>
							if LasersChanged = '1' and (InjectSiteLaser = '1') then
								state <= Pause;
								AlgorithmsStart <= '1';
							end if;
						when Pause=>
							if InjectDone = '1' then
								state <= Running;
								AlgorithmsStart <= '1';
							elsif EmergencyStopChanged = '1' and (EmergencyStop = '1') then
								state <= E_Stop;
								AlgorithmsStart <= '1';
							end if;
						
					end case;
				end if;
			end if;
		end if;
	end process;

	-- Event outputs and internal algorithm triggers depend solely on the current state
	process (state)
	begin
		--default values
		--events
		ConveyorChanged <= '0';
		ConveyorStoppedForInject <= '0';
		
		--algorithms
		ConveyorStart_alg_en <= '0'; 
		ConveyorStop_alg_en <= '0'; 
		ConveyorRunning_alg_en <= '0'; 
		ConveyorEStop_alg_en <= '0'; 

		case state is
			when E_Stop=>
				
			when Running=>
				ConveyorStart_alg_en <= '1';
				ConveyorChanged <= '1';
				
			when Pause=>
				ConveyorStop_alg_en <= '1';
				ConveyorChanged <= '1';
				ConveyorStoppedForInject <= '1';
				
			
		end case;
	end process;

	-- Algorithms process
	process(clk)
	begin
		if rising_edge(clk) then
			if AlgorithmsStart = '1' then			
				
				if ConveyorStart_alg_en = '1' then -- Algorithm ConveyorStart
					ConveyorStart_alg_done <= '0';
				end if;
				
				if ConveyorStop_alg_en = '1' then -- Algorithm ConveyorStop
					ConveyorStop_alg_done <= '0';
				end if;
				
				if ConveyorRunning_alg_en = '1' then -- Algorithm ConveyorRunning
					ConveyorRunning_alg_done <= '0';
				end if;
				
				if ConveyorEStop_alg_en = '1' then -- Algorithm ConveyorEStop
					ConveyorEStop_alg_done <= '0';
				end if;
				
			end if;

			
			if ConveyorStart_alg_done = '0' then -- Algorithm ConveyorStart

--begin algorithm raw text
ConveyorSpeed <= x"01";
ConveyorStart_alg_done <= '1';
--end algorithm raw text

			end if;
			
			if ConveyorStop_alg_done = '0' then -- Algorithm ConveyorStop

--begin algorithm raw text
ConveyorSpeed <= x"00";
ConveyorStop_alg_done <= '1';
--end algorithm raw text

			end if;
			
			if ConveyorRunning_alg_done = '0' then -- Algorithm ConveyorRunning

--begin algorithm raw text
ConveyorRunning_alg_done <= '1';
--end algorithm raw text

			end if;
			
			if ConveyorEStop_alg_done = '0' then -- Algorithm ConveyorEStop

--begin algorithm raw text
ConveyorEStop_alg_done <= '1';
--end algorithm raw text

			end if;
			
		end if;
	end process;

	--Done signal
	AlgorithmsDone <= (not AlgorithmsStart) and ConveyorStart_alg_done and ConveyorStop_alg_done and ConveyorRunning_alg_done and ConveyorEStop_alg_done;
	Done <= AlgorithmsDone;
end rtl;
