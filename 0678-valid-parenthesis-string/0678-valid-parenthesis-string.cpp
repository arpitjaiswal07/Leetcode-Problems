class Solution {
public:
    bool checkValidString(string s) {
        int ptr1 = 0, ptr2 = 0;
        for (char c : s) {
            if (c == '(') {
                ptr1++;
                ptr2++;
            }
            else if (c == ')') {
                ptr1--;
                ptr2--;
            }
            else { 
                ptr1--;   
                ptr2++;  
            }

            if (ptr2 < 0)
                return false;

            ptr1 = max(ptr1, 0);
        }

        return ptr1 == 0;
    }
};