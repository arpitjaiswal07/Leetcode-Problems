class Solution {
public:
    int minInsertions(string s) {
        int open_count = 0, insertions = 0;
        int i = 0;

        while (i < s.size()) {
            if (s[i] == '(') {
                open_count++;
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    insertions++;
                }

                if (open_count > 0) {
                    open_count--;
                } else {
                    insertions++;
                }
            }
            i++;
        }

        return insertions + 2 * open_count; 
    }
};