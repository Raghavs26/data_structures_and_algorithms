from typing import *


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = {}
        n, m = len(s) - 1, len(p) - 1

        def dfs(i: int, j: int, dp: Dict) -> bool:
            if i < 0 and j < 0:
                return True
            if i >= 0 and j < 0:
                return False
            if i < 0 and j >= 0:
                while j:
                    if p[j] != "*":
                        return False
                    j -= 1
                return True
            if (i, j) in dp:
                return dp[(i, j)]
            if s[i] == p[j] or p[j] == ".":
                dp[(i, j)] = dfs(i - 1, j - 1, dp)
                return dp[(i, j)]
            if p[j] == "*":
                dp[(i, j)] = dfs(i - 1, j, dp) or dfs(i, j - 1, dp)
                return dp[(i, j)]
            return False

        return dfs(n, m, dp)
