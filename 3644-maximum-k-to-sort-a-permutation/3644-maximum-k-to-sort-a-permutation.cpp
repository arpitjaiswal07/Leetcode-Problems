class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i != nums[i])
                ans &=nums[i];
        }

        return max(ans,0);
    }
};