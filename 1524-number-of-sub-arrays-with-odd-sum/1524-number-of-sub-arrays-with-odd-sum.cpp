class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int even_count = 1;
        int odd_count = 0;
        int current_parity = 0;
        long long total_subarrays = 0;

        for (int num : arr) {
            current_parity ^= (num & 1);
            if (current_parity == 1) {
                total_subarrays = (total_subarrays + even_count) % MOD;
                odd_count++;
            } else {
                total_subarrays = (total_subarrays + odd_count) % MOD;
                even_count++;
            }
        }

        return static_cast<int>(total_subarrays);
    }
};
