{{define "FBheader"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}
// This file represents the interface of Function Block {{$block.Name}}
#ifndef {{strToUpper $block.Name}}_H_
#define {{strToUpper $block.Name}}_H_

#include "fbtypes.h"

{{if .CvodeEnabled}}{{if blockNeedsCvode $block}}
#include "cvode/cvode.h"
#include "nvector/nvector_serial.h"
#include "cvode/cvode_dense.h"
#include "sundials/sundials_dense.h"
#include "sundials/sundials_types.h"
{{end}}{{end}}

{{if $block.CompositeFB}}//This is a CFB, so we need the #includes for the child blocks embedded here
{{range $currChildIndex, $child := $block.CompositeFB.FBs}}#include "{{$child.Type}}.h"
{{end}}{{end}}{{if $block.BasicFB}}//This is a BFB, so we need an enum type for the state machine
enum {{$block.Name}}_states { {{range $index, $state := $block.BasicFB.States}}{{if $index}}, {{end}}STATE_{{$block.Name}}_{{$state.Name}}{{end}} };
{{end}}

{{if $block.EventInputs}}union {{$block.Name}}InputEvents {
	struct {
	{{if $block.EventInputs}}{{range $index, $event := $block.EventInputs.Events}}	UDINT {{$event.Name}};
	{{end}}{{end}}} event;
	{{/*UDINT events[{{if $block.EventInputs}}{{add (div (len $block.EventInputs.Events) 32) 1}}{{else}}1{{end}}]; //this has been known to cause issues*/}}
};
{{else}}//this block had no input events
{{end}}{{if $block.Resources}}//This block is a device and probably contains resources
{{range $index, $res := $block.Resources}}#include "{{$res.Type}}.h"
{{end}}{{end}}

{{if $block.EventOutputs}}union {{$block.Name}}OutputEvents {
	struct {
	{{if $block.EventOutputs}}{{range $index, $event := $block.EventOutputs.Events}}	UDINT {{$event.Name}};
	{{end}}{{end}}} event;
	{{/*UDINT events[{{if $block.EventOutputs}}{{add (div (len $block.EventOutputs.Events) 32) 1}}{{else}}1{{end}}]; //this has been known to cause issues*/}}
};
{{else}}//this block had no output events
{{end}}

typedef struct {
    //input events
	{{if $block.EventInputs}}union {{$block.Name}}InputEvents inputEvents;{{end}}

    //output events
	{{if $block.EventOutputs}}union {{$block.Name}}OutputEvents outputEvents;{{end}}

    //input vars
	{{if $block.InputVars}}{{range $index, $var := $block.InputVars.Variables}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
    {{end}}{{end}}
    //output vars
	{{if $block.OutputVars}}{{range $index, $var := $block.OutputVars.Variables}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
    {{end}}{{end}}
	//any internal vars (BFBs only)
    {{if $block.BasicFB}}{{if $block.BasicFB.InternalVars}}{{range $varIndex, $var := $block.BasicFB.InternalVars.Variables}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
    {{end}}{{end}}{{end}}
	//any child FBs (CFBs only)
	{{if $block.CompositeFB}}{{range $currChildIndex, $child := $block.CompositeFB.FBs}}{{$child.Type}}_t {{$child.Name}};
	{{end}}{{end}}
	//resource vars
	{{if $block.ResourceVars}}{{range $index, $var := $block.ResourceVars}}{{$var.Type}} {{$var.Name}}{{if $var.ArraySize}}[{{$var.ArraySize}}]{{end}};
	{{end}}{{end}}
	//resources (Devices only)
	{{if $block.Resources}}{{range $index, $res := $block.Resources}}{{$res.Type}}_t {{$res.Name}};
	{{end}}{{end}}
	//state and trigger (BFBs only)
	{{if $block.BasicFB}}enum {{$block.Name}}_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	{{if .CvodeEnabled}}{{if blockNeedsCvode $block}}//this block uses cvode
	void *cvode_mem;
	N_Vector ode_solution;
	realtype T0;
	realtype Tnext;
	realtype Tcurr;
	{{end}}{{end}}

	{{end}}
} {{$block.Name}}_t;

//all FBs get a preinit function
int {{$block.Name}}_preinit({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me);

//all FBs get an init function
int {{$block.Name}}_init({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me);

//all FBs get a run function
void {{$block.Name}}_run({{$block.Name}}_t {{if or .TcrestUsingSPM (and $block.BasicFB .TcrestSmartSPM)}}_SPM{{end}} *me);

{{if not $block.BasicFB}}//composite/resource/device FBs get sync functions
void {{$block.Name}}_syncOutputEvents({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me);
void {{$block.Name}}_syncInputEvents({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me);

void {{$block.Name}}_syncOutputData({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me);
void {{$block.Name}}_syncInputData({{$block.Name}}_t {{if .TcrestUsingSPM}}_SPM{{end}} *me);

{{end}}

#endif
{{end}}