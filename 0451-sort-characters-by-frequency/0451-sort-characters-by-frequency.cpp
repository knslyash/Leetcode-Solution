class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> f;
        for( char x: s){
            f[x]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto i:f){
            q.push({i.second,i.first});
        }
        string ans="";
        while(q.size()){
            auto [d,u]=q.top();
            while(d--){
                ans+=u;
            }
            q.pop();
        }
        return ans;
    }
};