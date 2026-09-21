class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> answer(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums) {
            int mod = num % k;

            vector<long long> nextDp(k, 0);
            nextDp[mod]++;

            for(int r = 0; r < k; r++) {
                int newRemainder = (r * mod) % k;
                nextDp[newRemainder] += dp[r];
            }
            for(int r = 0; r < k; r++) {
                answer[r] += nextDp[r];
            }
            dp = nextDp;
        }
        return answer;
    }
};