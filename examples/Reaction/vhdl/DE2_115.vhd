-- This file has been automatically generated by go-iec61499-vhdl and should not be edited by hand
-- Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499-vhdl

-- This file represents the Composite Function Block for DE2_115

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;



entity DE2_115 is

	port(
		--for clock and reset signal
		clk		: in	std_logic;
		reset	: in	std_logic;
		enable	: in	std_logic;
		sync	: in	std_logic;
		
		
		
		
		
		--special emitted internal variables for child I/O
		tx_gpio : out std_logic; --type was BOOL 
		rx_gpio : in std_logic; --type was BOOL 
		
		--for done signal
		done : out std_logic
	);

end entity;


architecture rtl of DE2_115 is
	-- Signals needed for event connections 
	signal gpio_rx_rd_conn : std_logic;
	signal reaction_tx_change_conn : std_logic;

	-- Signals needed for data connections 
	signal gpio_rx_data_conn : std_logic; --type was BOOL
	signal reaction_tx_conn : std_logic; --type was BOOL

	-- Signals needed for the done signals 
	signal gpio_done : std_logic;
	signal reaction_done : std_logic;
begin
	--top level I/O to signals
	
	-- child I/O to signals
	
	gpio : entity work.BFB_GPIO port map(
		clk => clk,
		reset => reset,
		enable => enable,
		sync => sync,

		--event outputs 
		rx_rd_eO => gpio_rx_rd_conn,
		
		--event inputs
		tx_rd_eI => reaction_tx_change_conn, 
		
		--data outputs
		rx_data_O => gpio_rx_data_conn, 
		
		--data inputs
		tx_data_I => reaction_tx_conn,
		

		--specials
		tx_gpio => tx_gpio, --output
		rx_gpio => rx_gpio, --input
		
		done => gpio_done
	);
	
	reaction : entity work.BFB_Reaction port map(
		clk => clk,
		reset => reset,
		enable => enable,
		sync => sync,

		--event outputs 
		tx_change_eO => reaction_tx_change_conn,
		
		--event inputs
		rx_change_eI => gpio_rx_rd_conn, 
		
		--data outputs
		tx_O => reaction_tx_conn, 
		
		--data inputs
		rx_I => gpio_rx_data_conn,
		

		
		done => reaction_done
	);
	

	-- done signal
	done <= gpio_done and reaction_done;
	
end rtl;
