class Solution {
public:
    bool canJump(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++){
            if (x < i)
                return false;
            else
                x = max(x,i+nums[i]);
        }
        return true;
    }
};