//done
package main

import (
	"fmt"
)

func diStringMatch(s string) []int {
	minI := 0
	maxD := len(s)

	var ans []int

	for _, char := range s {
		if char == 'D' {
			ans = append(ans, maxD);
			maxD = maxD - 1;
		} else {
			ans = append(ans, minI);
			minI = minI + 1;
		}
	}
	fmt.Printf("maxD %v, minI %v", maxD, minI);
	if maxD == minI {
		ans = append(ans, maxD);
	} else {
		ans = append(ans, maxD-minI)
	}
	return ans
}

// func main() {
// 	var s string
// 	s = "IDID";
// 	// s = "III";
// 	// s = "DDDD";
// 	ans := diStringMatch(s);
// 	fmt.Printf("%v", ans);
// }
