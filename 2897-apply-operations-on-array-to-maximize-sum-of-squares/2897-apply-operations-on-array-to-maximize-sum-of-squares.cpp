class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1000000007;
        int count[31] = {0};

        for(int x : nums) {
            for(int i = 0; i < 31; i++) {
                if((x >> i) & 1) {
                    count[i]++;
                }
            }
        }
        long long ans = 0;

        while(k--) {
            long long x = 0;

            for(int i = 0; i < 31; i++) {
                if(count[i] > 0) {
                    x |= (1LL << i);
                    count[i]--;
                }
            }
            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};