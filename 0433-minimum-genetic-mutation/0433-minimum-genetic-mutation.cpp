class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set st(bank.begin(),bank.end());
        if(!st.count(endGene)) return -1;
        vector<char> gene={'A','C','G','T'};
        queue<pair<string,int>> q;
        q.push({startGene,0});
        while(q.size()){
            auto [curr,mut]=q.front();
            q.pop();
            if(curr==endGene){
                return mut;
            }
            for(int i=0;i<8;i++){
                auto ori=curr[i];
                for(char g:gene){
                    if(g==ori) continue;
                    curr[i]=g;
                    if(st.count(curr)){
                        q.push({curr,mut+1});
                        st.erase(curr);
                    }
                }
                curr[i]=ori;
            }
        }
        return -1;

    }
};