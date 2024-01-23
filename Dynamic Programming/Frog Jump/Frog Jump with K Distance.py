def solveUtil(ind, height, dp, k):
    if ind == 0:
        return 0
    if dp[ind] != -1:
        return dp[ind]

    mmSteps = float("inf")

    for j in range(1, k + 1):
        if ind - j >= 0:
            jump = solveUtil(ind - j, height, dp, k) + abs(
                height[ind] - height[ind - j]
            )
            mmSteps = min(jump, mmSteps)


    dp[ind] = mmSteps
    return dp[ind]


# Function to find the minimum cost to reach the end of the array
def solve(n, height, k):
    dp = [-1] * n  # Initialize a memoization array to store calculated results
    return solveUtil(n - 1, height, dp, k)  # Start the recursion from the last index


def main():
    height = [30, 10, 60, 10, 60, 50]
    n = len(height)
    k = 2
    print(solve(n, height, k))
