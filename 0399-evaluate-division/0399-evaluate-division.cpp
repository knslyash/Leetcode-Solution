class Solution {
public:

    bool dfs(int u, int target,
             vector<vector<pair<int, double>>>& adj,
             vector<bool>& visited,
             double product,
             double& result) {

        if (u == target) {
            result = product;
            return true;
        }

        visited[u] = true;

        for (auto [v, weight] : adj[u]) {

            if (visited[v])
                continue;

            if (dfs(v, target, adj, visited,
                    product * weight, result)) {
                return true;
            }
        }

        return false;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {

        unordered_map<string, int> mp;
        int id = 0;
        for (auto& eq : equations) {

            if (!mp.count(eq[0]))
                mp[eq[0]] = id++;

            if (!mp.count(eq[1]))
                mp[eq[1]] = id++;
        }

        vector<vector<pair<int, double>>> adj(id);

        for (int i = 0; i < equations.size(); i++) {

            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];

            double w = values[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 1.0 / w});
        }

        vector<double> ans;

        for (auto& query : queries) {

            string a = query[0];
            string b = query[1];

            if (!mp.count(a) || !mp.count(b)) {
                ans.push_back(-1.0);
                continue;
            }

            int u = mp[a];
            int v = mp[b];

            vector<bool> visited(id, false);

            double result = -1.0;

            dfs(u, v, adj, visited, 1.0, result);

            ans.push_back(result);
        }

        return ans;
    }
};