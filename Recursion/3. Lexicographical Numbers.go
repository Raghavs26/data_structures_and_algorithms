package main

func lexicalOrder(n int) []int {
	var res []int
	var solve func(int)
	

	solve = func(currentNumber int) {
		if currentNumber > n {
			return
		}
		res = append(res, currentNumber)
		for i := 0; i <= 9; i++ {
			newNumber := currentNumber*10 + i
			if newNumber > n {
				return
			}
			solve(newNumber)
		}
	}

	for i := 1; i <= 9; i++ {
		solve(i)
	}
	return res
}
