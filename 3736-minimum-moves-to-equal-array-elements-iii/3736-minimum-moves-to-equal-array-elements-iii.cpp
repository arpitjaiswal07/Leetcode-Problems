class Solution {
public:
    int minMoves(vector<int>& nums) {
       int max_num = *std::ranges::max_element(nums);
       int ans = 0;
       for (int num : nums){
            ans += (max_num - num);
       }
       return ans;
    }
};