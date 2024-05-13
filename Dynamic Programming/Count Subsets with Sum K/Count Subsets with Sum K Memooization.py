from typing import List


def findWays(arr: List[int], k: int) -> int:
    dp = {}

    def dfs(index: int, current_sum: int) -> int:
        if index < 0 or current_sum > k:
            return 0
        if current_sum == k:
            return 1
        if (index, current_sum) in dp:
            return dp[(index, current_sum)]

        if current_sum <= k and arr[index] <= current_sum:
            include = dfs(index - 1, current_sum + arr[index])
            exclude = dfs(index - 1, current_sum)
            dp[(index, current_sum)] = include + exclude
        else:
            dp[(index, current_sum)] = dfs(index - 1, current_sum)

        return dp[(index, current_sum)]

    res = dfs(len(arr) - 1, 0)
    return res


print(findWays([1, 1, 4, 5], 5))
