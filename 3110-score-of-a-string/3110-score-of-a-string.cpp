class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 1; i < s.length(); i++){
            score += abs((s[i] - '0')-(s[i-1] - '0'));
        }
        return score;
    }
};