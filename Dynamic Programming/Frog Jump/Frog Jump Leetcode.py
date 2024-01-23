class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if stones[1] - stones[0] > 1:
            return False

        dp = {}

        def can_reach(index, jump):
            if index == len(stones) - 1:
                return True

            if (index, jump) in dp:
                return dp[(index, jump)]

            for i in range(index + 1, len(stones)):
                diff = stones[i] - stones[index]
                if diff == jump or diff == jump - 1 or diff == jump + 1:
                    if can_reach(i, diff):
                        dp[(index, jump)] = True
                        return True

            dp[(index, jump)] = False
            return False

        return can_reach(0, 0)
