class Solution {
public:
    vector<int> pa,rank;
    int ex=0;
    int find(int x){
        if(pa[x]==x) return x;
        return pa[x]=find(pa[x]);
    }
    void unionf(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            ex++;
            return;}
        if(rank[pv]>rank[pu]){
            pa[pu]=pv;
        }
        else if(rank[pu]>rank[pv]) pa[pv]=pu;
        else{
            pa[pv]=pu;
            rank[pu]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n,0);
        pa.resize(n);
        for(int i=0;i<n;i++){
            pa[i]=i;
        }
        for(auto e:connections){
            unionf(e[0],e[1]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(find(i)==i) comp++;
        }
        return (ex>=comp-1)?comp-1:-1;
    }
};