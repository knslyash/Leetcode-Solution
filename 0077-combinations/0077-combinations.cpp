class Solution {
public:
    vector<vector<int>> ans;
    void com(vector<int>& num,int k,vector<int>& curr, int i){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(i==num.size()) return;
        curr.push_back(num[i]);
        com(num,k,curr,i+1);
        curr.pop_back();
        com(num,k,curr,i+1);

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> num;
        for(int i=1;i<n+1;i++){
            num.push_back(i);
        }
        vector<int> curr;
        int i=0;
        com(num,k,curr,i);
        return ans;
    }
};