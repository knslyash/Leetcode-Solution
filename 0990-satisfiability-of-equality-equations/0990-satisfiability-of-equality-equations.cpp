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
    bool equationsPossible(vector<string>& equations) {
        pa.resize(26);
        rank.resize(26,0);
        for( char c='a';c<='z';c++){
            pa[c-'a']=c-'a';
        }
        for(auto e: equations){
            if(e[1]=='='){
                unionf(e[0]-'a',e[3]-'a');
            }

        }
        for(auto ex:equations){
            if(ex[1]=='!'){
                if(find(ex[0]-'a')==find(ex[3]-'a')) return false;
            }
        }
        return true;
    }
};