class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i =0; i < nums.size(); i++){
           int num = nums[i];
            if(mp.find(num) != mp.end()){
                int j = mp[num];
                if (i - j <= k)
                    return true;
               }  
                mp[num] = i;
            }
        
        return false;
    }
};