class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');

        k = k - n;

        for(int i=n-1; i>=0; i--) {
            if(k >= 25) {
                res[i] = 'z';
                k -= 25;
            } else {
                res[i] = (char)(res[i] + k);
                break;
            }
        }
        return res;
    }
};