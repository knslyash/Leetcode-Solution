class Solution {
public:
    int d(vector<int>& c,int sum,int t,vector<int>&dp){
        if(sum==t){
            return 0;
        }
        if(sum>t){
            return 1e9;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans=1e9;
        for(int i=0;i<c.size();i++){
            if(c[i]<=t-sum)
                ans=min(ans,1+d(c,sum+c[i],t,dp));
        }
        return dp[sum]=ans;


    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=d(coins,0,amount,dp);
        return (ans>=1e9)?-1:ans;
    }
};