class Solution {
public:
    int minAddToMakeValid(string s) {
        int a = 0, b = 0;
        for (auto c : s){
            if(c == '(')
                b++;
            else{
                if (b == 0)
                    a++;
                else
                    b--;
            }
        }
       return b+a; 
    }
};