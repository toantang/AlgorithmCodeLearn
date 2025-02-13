package main

import (
	"fmt"
	"slices"
)

type Position struct {
	x int
	y int
}

func isPathCrossing(path string) bool {
	var tracking[]Position;
	tracking = append(tracking, Position{0, 0});

	for pos, val := range path {
		x := tracking[pos].x;
		y:= tracking[pos].y;

		if val == 'N' {
			y += 1
		} else if val == 'S' {
			y -= 1
		} else if val == 'E' {
			x += 1
		} else if val == 'W' {
			x -= 1
		}
		p := Position{x, y};
		if slices.Contains(tracking, p) {
			return true;
		}
		tracking = append(tracking, p);
	}

	return false
}

func main() {
	var path string
	path = "NES";
	path = "NESWW"
	path = "E"
	path = "SN";
	ans := isPathCrossing(path)
	fmt.Printf("ans: %v", ans)
}
