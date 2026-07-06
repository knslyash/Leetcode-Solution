class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
        int ans=0;
        while(q.size()){
            auto p=q.front();
            int i=p.first.first;
            int j=p.first.second;
            int dis=p.second;
            ans=max(ans,dis);
            q.pop();
            if(i-1>=0 && !vis[i-1][j]){
                vis[i-1][j]=1;
                q.push({{i-1,j},dis+1});
            }
            if(j-1>=0 && !vis[i][j-1]){
                vis[i][j-1]=1;
                q.push({{i,j-1},dis+1});
            }
            if(i+1<r && !vis[i+1][j]){
                vis[i+1][j]=1;
                q.push({{i+1,j},dis+1});
            }
            if(j+1<c && !vis[i][j+1]){
                vis[i][j+1]=1;
                q.push({{i,j+1},dis+1});
            }
        }
        return (ans==0)?-1:ans;
    }
};