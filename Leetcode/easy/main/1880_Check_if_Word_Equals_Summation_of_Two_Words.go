//done
package main

import (
	"math"
)

func converter(word string) int {
	var ans int;
	for pos, val := range word {
		ans += int(math.Floor(math.Pow10(len(word) - pos - 1))) * (int(val) - 97);
	}
	return ans;
}

func isSumEqual(firstWord string, secondWord string, targetWord string) bool {
    first := converter(firstWord);
	second := converter(secondWord);
	target := converter(targetWord);
	return first + second == target;
}

// func main() {
// 	var firstWord, secondWord, targetWord string;
// 	firstWord = "acb"
// 	secondWord = "cba";
// 	targetWord = "cdb";
// 	ans := isSumEqual(firstWord, secondWord, targetWord);
// 	fmt.Println(ans);
// }