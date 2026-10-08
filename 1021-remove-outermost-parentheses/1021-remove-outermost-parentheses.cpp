class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int level = 0;
        for(char ch : s) {
            if(ch == '(') {
                if(level > 0)
                    res += ch;
                    level++;                                        
                } else {
                    level--;
                    if(level > 0)
                    res += ch;            
            }
        }
        return res;
    }
};