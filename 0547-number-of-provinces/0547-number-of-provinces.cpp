class Solution {
public:
    void dfs(vector<vector<int>>& nums,vector<int>& vis,int city){
        vis[city]=1;
        for(int j=0;j<nums.size();j++){
            if(nums[city][j]==1 && vis[j]!=1){
                dfs(nums,vis,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(isConnected, vis, i);
            }
        }

        return provinces;
    }
};