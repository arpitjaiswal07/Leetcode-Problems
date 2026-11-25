class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n;
        int ans = n;

        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 100003ULL;
        const uint64_t BASE2 = 100019ULL;

        auto hasUniqueOfLength = [&](int len) -> bool {
            uint64_t h1 = 0, h2 = 0;
            uint64_t p1 = 1, p2 = 1;

            for (int i = 0; i < len - 1; ++i) {
                p1 = (p1 * BASE1) % MOD1;
                p2 = (p2 * BASE2) % MOD2;
            }

            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);

            for (int i = 0; i < n; ++i) {
                uint64_t val = static_cast<uint64_t>(nums[i]) + 1000000001ULL;
                h1 = (h1 * BASE1 + val) % MOD1;
                h2 = (h2 * BASE2 + val) % MOD2;

                if (i >= len - 1) {
                    uint64_t combined = (h1 << 32) | h2;
                    freq[combined]++;

                    uint64_t outVal = static_cast<uint64_t>(nums[i - len + 1]) + 1000000001ULL;
                    h1 = (h1 + MOD1 - (outVal * p1) % MOD1) % MOD1;
                    h2 = (h2 + MOD2 - (outVal * p2) % MOD2) % MOD2;
                }
            }

            for (const auto& [hashVal, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasUniqueOfLength(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
