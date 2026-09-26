class Solution {
public:
    bool solve(string& s, unordered_set<string>& set, int start, vector<int>& dp) {
        if(start == s.size()) {
            return true;
        }

        if(dp[start] != -1) {
            return dp[start];
        }

        for(int i = start; i < s.size(); i++) {
            string word = s.substr(start, i-start + 1);
            if(set.count(word) && solve(s, set, i+1, dp)) {
                return dp[start] = 1;
            }
        }
        return dp[start] = 0;
    }
 
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(s, set, 0, dp);
    }
};