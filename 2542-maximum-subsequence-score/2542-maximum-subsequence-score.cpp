class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums2.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());
        long long  sum=0;
        long long ans=0;
        priority_queue<int,
                        vector<int>,
                        greater<int>> pq; 
        for(int i=0;i<v.size();i++){
                pq.push(v[i].second);
                sum+=v[i].second;
                if(pq.size()>k){
                    auto u=pq.top();
                    sum-=u;
                    pq.pop();

                }
                if(pq.size()==k){
                    ans=max(ans,sum*v[i].first);
                }
                
        }
        return ans;

    }
};