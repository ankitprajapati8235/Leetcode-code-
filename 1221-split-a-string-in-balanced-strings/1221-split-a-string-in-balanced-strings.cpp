class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int l = 0, r = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') 
            l++;
            else
            r++;

            if(l == r)
            count++;
        }
        return count;
    }
};