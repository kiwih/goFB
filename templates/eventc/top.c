{{define "top"}}// This file has been automatically generated by goFB
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}
//This is the main file for the iec61499 network with {{$block.Name}} as the top level block

#include "{{$block.Name}}.h"

//TODO: replace all this with an invocation queue

//there will also be the emit function definition 

//the emit function will take an event ID and place the appropriate invocations onto the invocation queue

//when an event is consumed from the queue, its event function will be called

//data will be stored in the network and updated as necessary by event functions

//put a copy of the top level block into global memory
{{$block.Name}}_t my{{$block.Name}};

int main() {
	if({{$block.Name}}_preinit(&my{{$block.Name}}) != 0) {
		printf("Failed to preinitialize.");
		return 1;
	}
	if({{$block.Name}}_init(&my{{$block.Name}}) != 0) {
		printf("Failed to initialize.");
		return 1;
	}

	printf("Top: %20s   Size: %lu\n", "{{$block.Name}}", sizeof(my{{$block.Name}}));

	int tickNum = 0;
	do {
		//printf("=====TICK %i=====\n",tickNum);
		{{$block.Name}}_syncOutputEvents(&my{{$block.Name}});
		{{$block.Name}}_syncInputEvents(&my{{$block.Name}});

		{{$block.Name}}_syncOutputData(&my{{$block.Name}});
		{{$block.Name}}_syncInputData(&my{{$block.Name}});
		
		{{$block.Name}}_run(&my{{$block.Name}});
	} while(tickNum++ < 500);

	return 0;
}

{{end}}