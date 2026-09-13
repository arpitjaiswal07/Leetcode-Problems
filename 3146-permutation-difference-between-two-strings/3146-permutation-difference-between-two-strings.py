class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        ans = 0
        for c in s:
            ans = ans + abs(s.find(c)-t.find(c))
        return ans
