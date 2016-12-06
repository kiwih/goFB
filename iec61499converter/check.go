package iec61499converter

import (
	"errors"
	"strings"

	"github.com/kiwih/go-iec61499-vhdl/iec61499converter/iec61499"
)

//checkFB is used internally to ensure that a given inputted function block is amenable to this conversion tool
func (c *Converter) checkFB(fb *iec61499.FB) error {
	//1. Make sure all algorithms are written in VHDL
	if c.ignoreAlgorithmLanguages == false {
		if fb.BasicFB != nil {
			for i := 0; i < len(fb.BasicFB.Algorithms); i++ {
				if strings.ToLower(fb.BasicFB.Algorithms[i].Other.Language) != c.outputLanguage {
					return errors.New("Algorithm " + fb.BasicFB.Algorithms[i].Name + " in block " + fb.Name + " is not written in VHDL")
				}
			}
		}
	}

	//2. Ensure no use of STRING or ANY types in data or internal variables TODO
	return nil
}