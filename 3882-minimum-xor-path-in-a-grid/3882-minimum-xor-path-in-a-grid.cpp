
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> dp(n, vector<bool>(1024, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];

                if (i == 0 && j == 0) {
                    dp[j][val] = true;
                    continue;
                }

                vector<bool> curr(1024, false);

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[j][x]) {
                            curr[x ^ val] = true;
                        }
                    }
                }
                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[j - 1][x]) {
                            curr[x ^ val] = true;
                        }
                    }
                }

                dp[j] = curr;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
