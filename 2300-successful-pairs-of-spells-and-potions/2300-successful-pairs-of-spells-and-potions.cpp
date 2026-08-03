class Solution {
public:
    void bs(int t, vector<int>& potions, long long success,vector<int>& ans){
         int i=0,
             j=potions.size()-1;
        while(i<=j){
            int m=i+(j-i)/2;
            if((long long )t*potions[m]>=success){
                j=m-1;
            }
            else i=m+1;
        }
        ans.push_back(potions.size()-i);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
                bs(spells[i],potions,success,ans);
        }
        return ans;
    }
};