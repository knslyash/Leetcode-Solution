class Solution {
public:
       struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if (a.first == b.first)
                return a.second > b.second;  
            return a.first < b.first;        
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> f;
        for(string x: words){
            f[x]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> q;
        for(auto i: f){
            q.push({i.second,i.first});

        }
        vector<string> ans;
        while(k--){
            auto [d,u]=q.top();
            q.pop();
            ans.push_back(u);
        }
        return ans;
    }
};