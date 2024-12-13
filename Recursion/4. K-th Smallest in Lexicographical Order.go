package main

func countBattleships(board [][]byte) int {
	if len(board) == 0 || len(board[0]) == 0 {
		return 0
	}

	m, n := len(board), len(board[0])
	res := 0

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'X' {
				if (i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.') {
					res++
				}
			}
		}
	}
	return res
}
func findKthNumber(n int, k int) int {
	currentNumber := 1
	k -= 1
	var solve func(int) int
	solve = func(number int) int {
		count := 0
		first, last := number, number+1
		for first <= n {
			count += (last - first)
			first *= 10
			last *= 10
			last = min(last, n+1)
		}
		return count
	}

	for k > 0 {
		count := solve(currentNumber)
		if count <= k {
			currentNumber++
			k -= count
		} else {
			currentNumber *= 10
			k--
		}
	}
	return currentNumber
}
