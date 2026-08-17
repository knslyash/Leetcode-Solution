class Solution {
public:
    vector<int> dp;
    int g(int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=g(n-1)+g(n-2);
    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return g(n);
    }
};