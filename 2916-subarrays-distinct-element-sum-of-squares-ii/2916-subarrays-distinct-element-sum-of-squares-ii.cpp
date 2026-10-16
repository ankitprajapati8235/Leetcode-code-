
class Solution {
    static constexpr long long MOD = 1000000007LL;

    struct SegmentTree {
        int n;
        vector<long long> sum, sqSum, lazy;

        SegmentTree(int n) : n(n) {
            sum.assign(4 * n, 0);
            sqSum.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int l, int r, long long val) {
            long long len = r - l + 1;

            sqSum[node] = (
                sqSum[node]
                + 2 * val % MOD * sum[node] % MOD
                + val * val % MOD * len % MOD
            ) % MOD;

            sum[node] = (sum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = l + (r - l) / 2;

            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, 1);
                return;
            }

            push(node, l, r);

            int mid = l + (r - l) / 2;

            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (
                sum[node * 2] + sum[node * 2 + 1]
            ) % MOD;

            sqSum[node] = (
                sqSum[node * 2] + sqSum[node * 2 + 1]
            ) % MOD;
        }

        void updateRange(int l, int r) {
            if (l <= r) {
                update(1, 0, n - 1, l, r);
            }
        }

        long long getSquaredSum() {
            return sqSum[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree tree(n);
        unordered_map<int, int> lastSeen;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int l = 0;

            if (lastSeen.count(nums[r])) {
                l = lastSeen[nums[r]] + 1;
            }

            tree.updateRange(l, r);
            lastSeen[nums[r]] = r;

            ans = (ans + tree.getSquaredSum()) % MOD;
        }

        return static_cast<int>(ans);
    }
};
