class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++){
            int product = (i+1) * (27-(s[i]-'\0'-96));
            ans += product;
        }
        return ans;
    }
};