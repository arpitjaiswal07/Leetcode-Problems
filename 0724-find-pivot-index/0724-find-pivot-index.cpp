class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;

        for (int i : nums)
            total_sum += i;

        int left_sum = 0;

        for (int idx=0; idx<n; idx++){
            int right_sum = total_sum - left_sum - nums[idx];
            if (right_sum == left_sum)
                return idx;
            left_sum += nums[idx];       
        }
        return -1;
    }
};