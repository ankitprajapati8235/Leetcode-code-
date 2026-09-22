class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];
    };

    int k;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;
        res.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < 5; i++)
            res.cnt[i] = a.cnt[i];

        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int v = nums[l] % k;

            tree[node].prod = v;

            for (int i = 0; i < 5; i++)
                tree[node].cnt[i] = 0;

            tree[node].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int value) {
        if (l == r) {
            int v = value % k;

            tree[node].prod = v;

            for (int i = 0; i < 5; i++)
                tree[node].cnt[i] = 0;

            tree[node].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, value);
        else
            update(node * 2 + 1, mid + 1, r, pos, value);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            answer.push_back(res.cnt[x]);
        }

        return answer;
    }
};