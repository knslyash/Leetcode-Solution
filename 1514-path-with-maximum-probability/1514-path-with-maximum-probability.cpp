class Solution {
public:
    void dijkstra(vector<vector<pair<int,double>>>& adj,
                  int start,
                  vector<double>& pro) {

        priority_queue<pair<double,int>> pq;

        pro[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {

            auto [p, node] = pq.top();
            pq.pop();

            if (p < pro[node])
                continue;

            for (auto [next, prob] : adj[node]) {

                double newProb = p * prob;

                if (newProb > pro[next]) {
                    pro[next] = newProb;
                    pq.push({newProb, next});
                }
            }
        }
    }

    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node,
                          int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        vector<double> pro(n, 0.0);

        dijkstra(adj, start_node, pro);

        return pro[end_node];
    }
};