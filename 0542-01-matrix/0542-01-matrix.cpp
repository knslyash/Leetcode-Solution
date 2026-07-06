class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        int col=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(rows,vector<int> (col,0));
        vector<vector<int>> d(rows,vector<int> (col,0));
        for(int i=0;i<rows;i++)
            for(int j=0;j<col;j++)
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
        while(q.size()){
            auto p=q.front();
            int i=p.first.first;
            int j=p.first.second;
            int dis=p.second;
            d[i][j]=dis;
            q.pop();
            if(i-1>=0 && !vis[i-1][j]){
                q.push({{i-1,j},dis+1});
                vis[i-1][j]=1;
            }
            if(i+1<rows && !vis[i+1][j]){
                q.push({{i+1,j},dis+1});
                vis[i+1][j]=1;
            }
            if(j-1>=0 && !vis[i][j-1]){
                q.push({{i,j-1},dis+1});
                vis[i][j-1]=1;
            }
            if(j+1<col && !vis[i][j+1]){
                q.push({{i,j+1},dis+1});
                vis[i][j+1]=1;
            }
            
        }

        return d;
    }
};