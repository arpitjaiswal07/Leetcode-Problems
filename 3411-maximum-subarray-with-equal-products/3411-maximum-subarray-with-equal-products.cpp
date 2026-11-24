class Solution {
 public:
  int maxLength(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    const unsigned long long MAX_GL = 25200;

    for (int i = 0; i < n; ++i) {
      unsigned long long prod = 1;
      unsigned long long g = 0;
      unsigned long long l = 1;

      for (int j = i; j < n; ++j) {
        unsigned long long x = nums[j];
        prod *= x;

        if (prod > MAX_GL) {
          break;
        }

        g = std::gcd(g, x);
        l = std::lcm(l, x);

        if (prod == g * l) {
          ans = max(ans, j - i + 1);
        }
      }
    }

    return ans;
  }
};
