class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    if(nums.size()==0) return {-1,-1};
    int l = 0, r = nums.size() - 1;
    int u = -1, v = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target){
            u = mid;
            r = mid -1;
        }     
        else if(nums[mid] > target) 
            r = mid - 1;
        else 
            l = mid + 1;
    }
    ans.push_back(u);
    l = 0, r = nums.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target){
            v = mid;
            l = mid + 1;
        }     
        else if(nums[mid] > target) 
            r = mid - 1;
        else 
            l = mid + 1;
    }
    ans.push_back(v);
    return ans;
    }
};