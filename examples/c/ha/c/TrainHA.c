// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for TrainHA
#include "TrainHA.h"


/* TrainHA_preinit() is required to be called to 
 * initialise an instance of TrainHA. 
 * It sets all I/O values to zero.
 */
int TrainHA_preinit(TrainHA_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.tick = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.update = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_TrainHA_slow_mode_1_setup_0;
	

	
	me->cvode_mem = NULL;
	
	return 0;
}

/* TrainHA_init() is required to be called to 
 * set up an instance of TrainHA. 
 * It passes around configuration data.
 */
int TrainHA_init(TrainHA_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms




static int TrainHA_fast_mode_algo_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *f_data) {
	TrainHA_t *me = (TrainHA_t*)f_data;
	
	NV_Ith_S(ode_solution_dot, 0) = me->Vf;
	
	return 0;
}

void TrainHA_fast_mode_algo_f_tick(TrainHA_t *me) {
	me->Tnext += me->delta;
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	}
	
	me->x = NV_Ith_S(me->ode_solution, 0);
	
}





static int TrainHA_slow_mode_1_algo_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *f_data) {
	TrainHA_t *me = (TrainHA_t*)f_data;
	
	NV_Ith_S(ode_solution_dot, 0) = me->Vs;
	
	return 0;
}

void TrainHA_slow_mode_1_algo_f_tick(TrainHA_t *me) {
	me->Tnext += me->delta;
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	}
	
	me->x = NV_Ith_S(me->ode_solution, 0);
	
}





static int TrainHA_slow_mode_2_algo_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *f_data) {
	TrainHA_t *me = (TrainHA_t*)f_data;
	
	NV_Ith_S(ode_solution_dot, 0) = me->Vs;
	
	return 0;
}

void TrainHA_slow_mode_2_algo_f_tick(TrainHA_t *me) {
	me->Tnext += me->delta;
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	}
	
	me->x = NV_Ith_S(me->ode_solution, 0);
	
}





void TrainHA_fast_mode_setup_0_algo_cvode_init(TrainHA_t *me) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	
	//specify tolerances
	realtype reltol = 1e-6;
    realtype abstol = 1e-8;

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial(1); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	
	NV_Ith_S(me->ode_solution, 0) = me->x;
	
		
	me->T0 = 0; //???? should this always be 0 ????
	me->Tnext = 0; //this will always be 0, it represents the value of t we've counted to.
	me->Tcurr = 0; //the value of T the solver got to.

	//initialize solver with pointer to values
	flag = CVodeInit(me->cvode_mem, TrainHA_fast_mode_algo_f, me->T0, me->ode_solution);
    if (flag < 0) {
		fprintf(stderr, "Error in CVodeMalloc: %d\n", flag);
		while(1);
    }

	flag = CVodeSetUserData(me->cvode_mem, me);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSetUserData: %d\n", flag);
		while(1);
    }


	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, reltol, abstol);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}
}




void TrainHA_slow_mode_2_setup_0_algo_cvode_init(TrainHA_t *me) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	
	//specify tolerances
	realtype reltol = 1e-6;
    realtype abstol = 1e-8;

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial(1); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	
	NV_Ith_S(me->ode_solution, 0) = me->x;
	
		
	me->T0 = 0; //???? should this always be 0 ????
	me->Tnext = 0; //this will always be 0, it represents the value of t we've counted to.
	me->Tcurr = 0; //the value of T the solver got to.

	//initialize solver with pointer to values
	flag = CVodeInit(me->cvode_mem, TrainHA_slow_mode_2_algo_f, me->T0, me->ode_solution);
    if (flag < 0) {
		fprintf(stderr, "Error in CVodeMalloc: %d\n", flag);
		while(1);
    }

	flag = CVodeSetUserData(me->cvode_mem, me);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSetUserData: %d\n", flag);
		while(1);
    }


	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, reltol, abstol);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}
}




void TrainHA_slow_mode_1_setup_0_algo_cvode_init(TrainHA_t *me) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	
	//specify tolerances
	realtype reltol = 1e-6;
    realtype abstol = 1e-8;

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial(1); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	
	NV_Ith_S(me->ode_solution, 0) = 0;
	
		
	me->T0 = 0; //???? should this always be 0 ????
	me->Tnext = 0; //this will always be 0, it represents the value of t we've counted to.
	me->Tcurr = 0; //the value of T the solver got to.

	//initialize solver with pointer to values
	flag = CVodeInit(me->cvode_mem, TrainHA_slow_mode_1_algo_f, me->T0, me->ode_solution);
    if (flag < 0) {
		fprintf(stderr, "Error in CVodeMalloc: %d\n", flag);
		while(1);
    }

	flag = CVodeSetUserData(me->cvode_mem, me);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSetUserData: %d\n", flag);
		while(1);
    }


	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, reltol, abstol);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}
}





void TrainHA_fast_mode_algo(TrainHA_t  *me) {
//AUTOGENERATED CVODE CODE: this is a cvode algorithm, so is defined elsewhere
	TrainHA_fast_mode_algo_f_tick(me);

}

void TrainHA_slow_mode_1_algo(TrainHA_t  *me) {
//AUTOGENERATED CVODE CODE: this is a cvode algorithm, so is defined elsewhere
	TrainHA_slow_mode_1_algo_f_tick(me);

}

void TrainHA_slow_mode_2_algo(TrainHA_t  *me) {
//AUTOGENERATED CVODE CODE: this is a cvode algorithm, so is defined elsewhere
	TrainHA_slow_mode_2_algo_f_tick(me);

}

void TrainHA_fast_mode_setup_0_algo(TrainHA_t  *me) {
//AUTOGENERATED CVODE CODE: see TrainHA_fast_mode_setup_0_algo_cvode_init()
	TrainHA_fast_mode_setup_0_algo_cvode_init(me);

}

void TrainHA_slow_mode_2_setup_0_algo(TrainHA_t  *me) {
//AUTOGENERATED CVODE CODE: see TrainHA_slow_mode_2_setup_0_algo_cvode_init()
	TrainHA_slow_mode_2_setup_0_algo_cvode_init(me);

}

void TrainHA_slow_mode_1_setup_0_algo(TrainHA_t  *me) {
//AUTOGENERATED CVODE CODE: see TrainHA_slow_mode_1_setup_0_algo_cvode_init()
	TrainHA_slow_mode_1_setup_0_algo_cvode_init(me);

}



/* TrainHA_run() executes a single tick of an
 * instance of TrainHA according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void TrainHA_run(TrainHA_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.update = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_TrainHA_slow_mode_1_setup_0:
			if(true) {
				me->_state = STATE_TrainHA_slow_mode_1;
				me->_trigger = true;
			};
			break;
		case STATE_TrainHA_slow_mode_1:
			if(me->inputEvents.event.tick && (me->x >= 0 && me->x < 5)) {
				me->_state = STATE_TrainHA_slow_mode_1;
				me->_trigger = true;
			} else if(me->inputEvents.event.tick && (me->x = 5)) {
				me->_state = STATE_TrainHA_fast_mode_setup_0;
				me->_trigger = true;
			};
			break;
		case STATE_TrainHA_fast_mode:
			if(me->inputEvents.event.tick && (me->x >= 5 && me->x < 15)) {
				me->_state = STATE_TrainHA_fast_mode;
				me->_trigger = true;
			} else if(me->inputEvents.event.tick && (me->x = 15)) {
				me->_state = STATE_TrainHA_slow_mode_2_setup_0;
				me->_trigger = true;
			};
			break;
		case STATE_TrainHA_slow_mode_2:
			if(me->inputEvents.event.tick && (me->x >= 15 && me->x < 25)) {
				me->_state = STATE_TrainHA_slow_mode_2;
				me->_trigger = true;
			} else if(me->inputEvents.event.tick && (me->x = 25)) {
				me->_state = STATE_TrainHA_slow_mode_1_setup_0;
				me->_trigger = true;
			};
			break;
		case STATE_TrainHA_fast_mode_setup_0:
			if(true) {
				me->_state = STATE_TrainHA_fast_mode;
				me->_trigger = true;
			};
			break;
		case STATE_TrainHA_slow_mode_2_setup_0:
			if(true) {
				me->_state = STATE_TrainHA_slow_mode_2;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_TrainHA_slow_mode_1_setup_0:
			TrainHA_slow_mode_1_setup_0_algo(me);
			break;

		case STATE_TrainHA_slow_mode_1:
			TrainHA_slow_mode_1_algo(me);
			me->outputEvents.event.update = 1;
			break;

		case STATE_TrainHA_fast_mode:
			TrainHA_fast_mode_algo(me);
			me->outputEvents.event.update = 1;
			break;

		case STATE_TrainHA_slow_mode_2:
			TrainHA_slow_mode_2_algo(me);
			me->outputEvents.event.update = 1;
			break;

		case STATE_TrainHA_fast_mode_setup_0:
			TrainHA_fast_mode_setup_0_algo(me);
			break;

		case STATE_TrainHA_slow_mode_2_setup_0:
			TrainHA_slow_mode_2_setup_0_algo(me);
			break;

		
		}
	}

	me->_trigger = false;
}


