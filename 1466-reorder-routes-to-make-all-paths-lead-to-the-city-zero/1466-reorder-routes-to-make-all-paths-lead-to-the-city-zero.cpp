class Solution {
public:
    void dfs(int node,int& ans,vector<int>& vis,vector<vector<pair<int,int>>>& adj){
        vis[node]=1;
        for(auto [n,c]:adj[node]){
            if(!vis[n]){
                ans+=c;
                dfs(n,ans,vis,adj);
            }
        }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        vector<int> vis(n,0);
        int ans=0;
        dfs(0,ans,vis,adj);
        return ans;

    }
};