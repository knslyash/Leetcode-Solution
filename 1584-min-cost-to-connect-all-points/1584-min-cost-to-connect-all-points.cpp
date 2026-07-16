class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int x = points[i][0];
                int y = points[i][1];

                int a = points[j][0];
                int b = points[j][1];

                int dist = abs(x-a) + abs(y-b);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> vis(n, 0);

        pq.push({0,0});

        int mst = 0;

        while(!pq.empty()) {

            auto [d,u] = pq.top();
            pq.pop();

            if(vis[u]) continue;

            vis[u] = 1;
            mst += d;

            for(auto [v,w] : adj[u]) {

                if(!vis[v]) {
                    pq.push({w,v});
                }
            }
        }

        return mst;
    }
};