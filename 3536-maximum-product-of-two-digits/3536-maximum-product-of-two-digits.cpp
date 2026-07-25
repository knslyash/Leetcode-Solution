class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            pq.push(s[i]-'0');
            if(pq.size()>2) pq.pop();
        }
        auto a=pq.top();pq.pop();
        auto b=pq.top();
        return a*b;
    }
};