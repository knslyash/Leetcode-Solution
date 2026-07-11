class Solution {
public:
    void dijkstra(vector<vector<pair<int,int>>>& adj,vector<int>& dis,int src){
        dis[src]=0;
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,src});
        while(q.size()){
            auto [d,u]=q.top();
            q.pop();
            if(d>dis[u]) continue;
            for( auto nei: adj[u]){
                if(dis[nei.first]>dis[u]+nei.second){
                    dis[nei.first]=dis[u]+nei.second;
                    q.push({dis[nei.first],nei.first});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dis(n+1,INT_MAX);
        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        dijkstra(adj,dis,k);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX){
                return -1;
            }else{
                ans=max(ans,dis[i]);
            }
        }
        
        return ans;
    }
};