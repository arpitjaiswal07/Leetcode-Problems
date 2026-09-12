class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int k = 1, j = 2;
        for (int i=3; i<=n; i++) {
            int m = j+k;
            k = j;
            j = m;
        }

        return j;
    }
};
