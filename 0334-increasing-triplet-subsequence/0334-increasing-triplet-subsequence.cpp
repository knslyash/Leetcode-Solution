class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX,second=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<first){
                first=nums[i];
            }
            if(nums[i]<second && nums[i]>first){
                second=nums[i];
            }
            if(first<second && second<nums[i]){
                return true;
            }
        }
        return false;
    }
};