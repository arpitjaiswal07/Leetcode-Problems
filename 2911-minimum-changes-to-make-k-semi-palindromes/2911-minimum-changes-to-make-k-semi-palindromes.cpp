#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> divisors(n + 1);
        for (int d = 1; d <= n / 2; ++d) {
            for (int len = d * 2; len <= n; len += d) {
                divisors[len].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_changes = INF;
                for (int d : divisors[len]) {
                    int changes = 0;
                    for (int offset = 0; offset < d; ++offset) {
                        int left = i + offset;
                        int right = j - d + 1 + offset;
                        while (left < right) {
                            if (s[left] != s[right]) {
                                ++changes;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    min_changes = min(min_changes, changes);
                }
                cost[i][j] = min_changes;
            }
        }

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int p = 1; p <= k; ++p) {
            vector<int> next_dp(n + 1, INF);
            for (int i = 2 * p; i <= n; ++i) {
                for (int m = 2 * (p - 1); m <= i - 2; ++m) {
                    if (dp[m] != INF) {
                        next_dp[i] = min(next_dp[i], dp[m] + cost[m][i - 1]);
                    }
                }
            }
            dp = move(next_dp);
        }

        return dp[n];
    }
};
