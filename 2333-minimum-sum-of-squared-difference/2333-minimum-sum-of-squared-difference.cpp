class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;
        vector<long long> diff(n);

        long long total = 0;
        long long mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (k >= total) return 0;

        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long ops = 0;

            for (long long d : diff) {
                if (d > mid) {
                    ops += d - mid;
                }
            }

            if (ops <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long level = low;
        long long ops = 0;
        long long ans = 0;

        for (long long d : diff) {
            if (d > level) {
                ops += d - level;
                d = level;
            }
            ans += d * d;
        }

        long long rem = k - ops;
        ans -= rem * (2 * level - 1);

        return ans; 
    }
};