package main

import "strings"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func mostWordsFound(sentences []string) int {
	res := 0
	for _, sentence := range sentences {
		res = max(res, len(strings.Split(sentence, " ")))
	}
	return res
}
