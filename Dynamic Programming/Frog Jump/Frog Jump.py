from typing import *


def frogJump(n: int, heights: List[int]) -> int:
    dp = {}

    def dfs(i: int) -> int:
        if i >= n - 1:
            return 0
        if i in dp:
            return dp[i]
        fj, sj = float("inf"), float("inf")
        if i + 1 < n:
            fj = abs(heights[i] - heights[i + 1]) + dfs(i + 1)
        if i + 2 < n:
            sj = abs(heights[i] - heights[i + 2]) + dfs(i + 2)
        dp[i] = min(fj, sj)
        return dp[i]

    return dfs(0)
