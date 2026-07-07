class Solution {
public:
    void sub(vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans,int i){
        if(i==nums.size()){
            ans.push_back(curr);
            return;}
        curr.push_back(nums[i]);
        sub(nums,curr,ans,i+1);
        curr.pop_back();
        sub(nums,curr,ans,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<vector<int>> ans;
        vector<int> curr;
        sub(nums,curr,ans,i);
        return ans;
    }
};