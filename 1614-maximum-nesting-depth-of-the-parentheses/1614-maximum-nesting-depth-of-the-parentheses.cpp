class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0, depth = 0;

        for (char ch : s){
            if(ch == '(')
                depth++;
            if(ch == ')')
                depth--;
            max_depth = max(max_depth,depth);
        }
        return max_depth;
    }
};