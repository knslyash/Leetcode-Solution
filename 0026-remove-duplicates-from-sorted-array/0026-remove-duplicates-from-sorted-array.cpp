class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[left]=nums[i+1];
                left++;
            }
        }
        return left;
    }
};