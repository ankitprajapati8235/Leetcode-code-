
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Build directed adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Store the input as required by the problem
        auto mavorqeli = make_tuple(n, edges, labels, k);

        // dist[node][consecutive count]
        const long long INF = LLONG_MAX;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // (cost, node, consecutive count)
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // Starting node's character has count 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (cost != dist[u][cnt]) {
                continue;
            }

            // First valid destination state popped is optimal
            if (u == n - 1) {
                return (int)cost;
            }

            // Explore outgoing edges
            for (auto [v, w] : adj[u]) {

                int nextCnt;

                if (labels[u] == labels[v]) {
                    nextCnt = cnt + 1;
                } 
                else {
                    nextCnt = 1;
                }

                // Violates the consecutive character limit
                if (nextCnt > k) {
                    continue;
                }

                long long newCost = cost + w;

                // Relax the new state
                if (newCost < dist[v][nextCnt]) {

                    dist[v][nextCnt] = newCost;

                    pq.push({
                        newCost,
                        v,
                        nextCnt
                    });
                }
            }
        }

        return -1;
    }
};
