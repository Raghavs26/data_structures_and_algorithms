class Solution:
    def minDifference(self, arr, n):
        dp = {}

        def dfs(i, s1, s2):
            if i == 0:
                return abs(s1 - s2)
            if (i, s1) in dp:
                return dp[(i, s1)]

            S1 = dfs(i - 1, arr[i - 1] + s1, s2)
            S2 = dfs(i - 1, s1, s2 + arr[i - 1])
            dp[(i, s1)] = min(S1, S2)
            return dp[(i, s1)]

        return dfs(n, 0, 0)


obj = Solution()
print(obj.minDifference([1, 6, 11, 5], 4))
