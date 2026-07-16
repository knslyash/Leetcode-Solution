class Solution {
public:

    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {

            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;

            return true;
        }
    };

    int kruskal(vector<vector<int>>& edges,
                int n,
                int skip,
                int force) {

        DSU dsu(n);

        int cost = 0;
        int cnt = 0;

        if (force != -1) {

            auto &e = edges[force];

            if (dsu.unite(e[0], e[1])) {

                cost += e[2];
                cnt++;
            }
        }

        for (int i = 0; i < edges.size(); i++) {

            if (i == skip)
                continue;

            auto &e = edges[i];

            if (dsu.unite(e[0], e[1])) {

                cost += e[2];
                cnt++;
            }
        }

        if (cnt != n - 1)
            return INT_MAX;

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges) {

        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int mst = kruskal(edges, n, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < edges.size(); i++) {

            if (kruskal(edges, n, i, -1) > mst) {

                critical.push_back(edges[i][3]);

            } else if (kruskal(edges, n, -1, i) == mst) {

                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};