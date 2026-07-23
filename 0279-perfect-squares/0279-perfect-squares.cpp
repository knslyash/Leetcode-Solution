class Solution {
public:
    int d(int n,int sum,vector<int>& dp){
        if(sum==n){
            return 0;
        }
        
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans=INT_MAX;
        for(int i=1;i*i<=n-sum;i++){
            
            ans=min(ans,1+d(n,sum+(i*i),dp));
        }
        return dp[sum]=ans;

    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return d(n,0,dp);
    }
};