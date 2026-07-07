class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for( auto c:p){
            adj[c[1]].push_back(c[0]);
            indegree[c[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(q.size()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        if (ans.size() != n)
            return {};
        return ans;
    }
};