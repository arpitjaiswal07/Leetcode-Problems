class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a= int(a, 2)
        b = int(b, 2)
        sum = a+b
        c=str(bin(sum)[2:])
        return c