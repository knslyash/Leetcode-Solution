class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a=nums[0];
        for(int i=1;i<nums.size();i++){
            a^=nums[i];
        }
        int ans=0;
        for(int i=0;i<32;i++){
            auto abit=(a>>i)&1;
            auto kbit=(k>>i)&1;
            if(kbit!=abit){
                ans++;
            }
        }
        return ans;
    }
};