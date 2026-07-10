class Solution {
public:
    vector<int> pa,rank;
    int find(int x){
        if(pa[x]==x) return x;
        return pa[x]=find(pa[x]);
    }
    void unionf(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pv]>rank[pu]){
            pa[pu]=pv;
        }
        else if(rank[pu]>rank[pv]) pa[pv]=pu;
        else{
            pa[pv]=pu;
            rank[pu]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj(edges.size());
        pa.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            pa[i]=i;
        }
        for(auto edge:edges){
            unionf(edge[0],edge[1]);
        }
        return find(source)==find(destination);
    }
};