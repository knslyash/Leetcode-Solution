class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int n=0;
        for(int num:nums){
            n^=num;
        }
        unsigned int  m=n&(-n);
        int a=0;
        int b=0;
        for(int x:nums){
            if(x&m){
                a^=x;
            }
            else{
                b^=x;
            }
        }
        return {a,b};

    }
};