class Solution {
public:
    void dfs(vector<vector<int>>& adj,int k,vector<int>& vis){
        vis[k]=1;
        for(int x:adj[k]){
            if(!vis[x]){
                dfs(adj,x,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        for(auto& edge: invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        } 
        dfs(adj,k,vis);
        vector<int> ans;
        for(auto edge: invocations){
            if(!vis[edge[0]] && vis[edge[1]]){
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};