class Solution {
public:
   
    int dfs(vector<vector<int>>& grid,int i,int j){
        int r=grid.size();
        int c=grid[0].size();
        if(i<0 || j<0 ||i>=r ||j>=c|| grid[i][j]==0){
            return 0 ;
        }
        grid[i][j]=0;
        return dfs(grid,i-1,j)+
                dfs(grid,i+1,j)
                +dfs(grid,i,j-1)
                +dfs(grid,i,j+1)+1;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};