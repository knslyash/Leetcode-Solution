class Solution {
public:
        vector<int> rank,pa;
    int find(int x){
        if(pa[x]==x){
            return x;
        }
        return pa[x]=find(pa[x]);
        
    }
    void unionf(int u ,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            pa[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            pa[pu]=pv;
        }
        else{
            pa[pv]=pu;
            rank[pu]++;
        }

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        pa.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<n+1;i++){
            pa[i]=i;
            rank[i]=0;
        }
        for(auto edge: edges){
            if(find(edge[0])==find(edge[1])){
                return edge;
            }
            unionf(edge[0],edge[1]);
        }
        return {};
    }
};