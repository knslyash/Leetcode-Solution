class Solution {
public:
    bool canJump(vector<int>& nums) {
        int f=0;
        for(int i=0;i<nums.size();i++){
            if(i>f){
                return false;
            }
            f=max(f,i+nums[i]);
        }
        return true;
    }
};