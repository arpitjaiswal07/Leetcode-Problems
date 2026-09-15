class Solution:
    def secondHighest(self, s: str) -> int:
        high = -1
        sec_high = -1

        for ch in s:
            if ch.isdigit():
                num = int(ch)

                if num > high:
                    sec_high = high
                    high = num

                elif num < high and num > sec_high:
                    sec_high = num

        return sec_high