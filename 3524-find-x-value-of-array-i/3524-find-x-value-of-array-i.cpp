class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k);

        for (int x: nums) {
            int rem = x% k;
            vector<long long> next(k);

            next[rem] = 1;

            for (int i = 0; i < k; i++) {
                int new_rem = (i * rem) % k;
                next[new_rem] += dp[i];
            }

            for (int i = 0; i < k; i++) {
                ans[i] += next[i];
            }

            dp = next;
        }

        return ans;
    }
};
