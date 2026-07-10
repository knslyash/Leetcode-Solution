class Solution {
public:
    vector<int> rank,pa;
    int find(int x){
        if(pa[x]==x){
            return x;
        }
        return pa[x]=find(pa[x]);
    }
    void unionf(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return ;
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
    int findCircleNum(vector<vector<int>>& i) {
        pa.resize(i.size());
        rank.resize(i.size(),0);
        for(int k=0;k<i.size();k++){
                pa[k]=k;
        }
        for(int k=0;k<i.size();k++){
            for(int j=k+1;j<i.size();j++){
                if(i[k][j]==1){
                    unionf(k,j);
                }
            }
                
        }
        int ans=0;
        for(int k=0;k<i.size();k++){
            if(find(k)==k) ans++;
        }
    return ans;

        
    }
};