package main

func shortestPalindrome(s string) string {
	reverseString := func(input string) string {
		runes := []rune(input)
		for left, right := 0, len(runes)-1; left < right; left, right = left+1, right-1 {
			runes[left], runes[right] = runes[right], runes[left]
		}
		return string(runes)
	}

	rev := reverseString(s)

	for i := 0; i < len(s); i++ {
		if s[:len(s)-i] == rev[i:] {
			return rev[:i] + s
		}
	}
	return rev + s
}
