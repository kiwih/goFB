package iec61499converter

import "github.com/kiwih/goFB/iec61499converter/iec61499"

//EventLink is turned into EventLinkMap which is map[int]EventLink
//We can use EventLinks to store connected event ports (from sources to destinations) of instances of blocks
type EventLink struct {
	Sources      []iec61499.Event
	Destinations []iec61499.Event
}

type Instance struct {
	iec61499.FBReference
	children []Instance
}

func GetEventLinkMap(fbs []iec61499.FB, topFB iec61499.FB) map[int]EventLink {
	return nil
}

func GetTopDownInstances(fbs []iec61499.FB, topFB iec61499.FB) Instance {

}
