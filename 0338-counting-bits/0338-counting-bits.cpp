class Solution {
public:
    int countbit(int n){
        int count=0;
        for(int i=31;i>=0;i--){
            if((n>>i)&1==1){
                count++;
            }
        }
        return count;
        
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i=1;i<=n;i++){
            ans[i]=countbit(i);
        }
        return ans;
    }
};