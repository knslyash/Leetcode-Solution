class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<2*nums.size();i++){
            while(!st.empty() && nums[i%nums.size()]>nums[st.top()]){
                ans[st.top()]=nums[i%nums.size()];
                st.pop();
            }if(i<nums.size())
                st.push(i);
        }
        return ans;
    }
};