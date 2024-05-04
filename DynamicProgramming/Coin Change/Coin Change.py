from typing import *


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        def recur(dp: Dict, index: int, amount: int) -> int:
            if amount < 0 or index < 0:
                return float("inf")
            if amount == 0:
                return 0
            if (index, amount) in dp:
                return dp[(index, amount)]

            if amount > 0:
                dp[(index, amount)] = min(
                    recur(dp, index - 1, amount),
                    recur(dp, index, amount - coins[index - 1]) + 1,
                )

            else:
                dp[(index, amount)] = recur(dp, index - 1, amount)
            return dp[(index, amount)]

        dp = {}
        res = recur(dp, len(coins) - 1, amount)
        return -1 if res == float("inf") else res
