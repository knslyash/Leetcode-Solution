class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> r;
        for(int i=0;i<nums.size();i++){
            if(r.find(target-nums[i])!=r.end()){
                return {r[target-nums[i]],i};
            }
            r[nums[i]]=i;
        }
        return {};
    }
};