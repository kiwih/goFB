//This is the main file for the iec61499 network with _TCREST as the top level block

#include "fbtypes.h"
#include "c0__Core0.h"
#include "c1__Core1.h"
#include "c2__Core2.h"
#include "c3__Core3.h"

//put a copy of the top level block into global memory
//struct _TCREST my_TCREST;

const int NOC_MASTER = 0;

volatile _UNCACHED int c0init = 0;
volatile _UNCACHED int c1init = 0;
volatile _UNCACHED int c2init = 0;
volatile _UNCACHED int c3init = 0;

void t0(void* param);
void t1(void* param);
void t2(void* param);
void t3(void* param);

void task0(c0__Core0 * c0);
void task1(c1__Core1 * c1);
void task2(c2__Core2 * c2);
void task3(c3__Core3 * c3);


int main() {
	printf("fbc sawmill2_mem tcrest4 startup.\n");
	printf("sizes: %lu, %lu, %lu, %lu\n", sizeof(c0__Core0), sizeof(c1__Core1), sizeof(c2__Core2), sizeof(c3__Core3));
	mp_init();
	printf("Starting t1,t2,t3 and initialising my_TCREST...\n");
	corethread_t core1 = 1;
	corethread_create(&core1, &t1, NULL);
	corethread_t core2 = 2;
	corethread_create(&core2, &t2, NULL);
	corethread_t core3 = 3;
	corethread_create(&core3, &t3, NULL);
	printf("Started t1,t2,t3\n");

	t0(NULL);
	int* res;
	//corethread_join(core1, (void**)&res);

	return 0;
}

void __attribute__ ((noinline)) timed_task0(c0__Core0 * c0) {
	c0__Core0run(c0);
}

void __attribute__ ((noinline)) timed_task1(c1__Core1 * c1) {
	c1__Core1run(c1);
}

void __attribute__ ((noinline)) timed_task2(c2__Core2 * c2) {
	c2__Core2run(c2);
}

void __attribute__ ((noinline)) timed_task3(c3__Core3 * c3) {
	c3__Core3run(c3);
}

void task0(c0__Core0 * c0) {
	//task0 runs core0
	unsigned int tickCount = 0;

	unsigned long long start_time;
	unsigned long long end_time;

	do {
		start_time = get_cpu_cycles();

		timed_task0(c0);

		end_time = get_cpu_cycles();
		//printf("%4d\t\t%lld\n", tickCount, end_time-start_time-3);

		tickCount++;
	} while(1);
}

void t0(void* param) {
	HEX = 7;
	c0__Core0 * c0;
	c0__Core0 c;
	c0 = &c; //SPM_BASE;

	c0__Core0init(c0);

	HEX = 8;

	if(mp_init_ports() == 0) {
		HEX = 16;
		return;
	}
	HEX = 9;

	c0init = 1;
	while(c0init == 0 || c1init == 0 || c2init == 0 || c3init == 0);

	HEX = 10;
	
	task0(c0);
}



void task1(c1__Core1 * c1) {
	unsigned int tickCount = 0;

	unsigned long long start_time;
	unsigned long long end_time;

	do {
		start_time = get_cpu_cycles();

		timed_task1(c1);

		end_time = get_cpu_cycles();
		//printf("%5d\t\t%lld\n", tickCount, end_time-start_time-3);

		tickCount++;
	} while(1);
}

void t1(void* param) {
	HEX = 7;
	c1__Core1 * c1;
	c1__Core1 c;
	c1 = &c; //SPM_BASE;

	c1__Core1init(c1);

	HEX = 8;

	if(mp_init_ports() == 0) {
		HEX = 16;
		return;
	}
	HEX = 9;

	c1init = 1;
	while(c0init == 0 || c1init == 0 || c2init == 0 || c3init == 0);

	HEX = 10;
	task1(c1);
}

void task2(c2__Core2 * c2) {
	//taskn runs coren
	do {
		timed_task2(c2);
	} while(1);
}

void t2(void* param) {
	HEX = 7;
	c2__Core2 * c2;
	c2__Core2 c;
	c2 = &c; //SPM_BASE;

	c2__Core2init(c2);

	HEX = 8;

	if(mp_init_ports() == 0) {
		HEX = 16;
		return;
	}
	HEX = 9;

	c2init = 1;
	while(c0init == 0 || c1init == 0 || c2init == 0 || c3init == 0);

	HEX = 10;
	
	task2(c2);
}


void task3(c3__Core3 * c3) {
	//taskn runs coren
	do {
		timed_task3(c3);
	} while(1);
}

void t3(void* param) {
	HEX = 7;

	c3__Core3 * c3;
	c3__Core3 c;
	c3 = &c; //SPM_BASE;

	c3__Core3init(c3);

	HEX = 8;

	if(mp_init_ports() == 0) {
		HEX = 16;
		return;
	}
	HEX = 9;

	c3init = 1;
	while(c0init == 0 || c1init == 0 || c2init == 0 || c3init == 0);

	HEX = 10;
	
	task3(c3);
}