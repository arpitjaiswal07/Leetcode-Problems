class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> num = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i+1 < n && num[s[i]] < num[s[i + 1]])
                ans -= num[s[i]];
            else
                ans += num[s[i]];
        }

        return ans;
    }
};
