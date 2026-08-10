class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int dist=0;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(q.size()){
            int n=q.size();
            dist++;
            while(n--){
            auto [i,j]=q.front();
            q.pop();
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];

                    if(nr<0 || nr>=maze.size() || nc<0 ||nc>=maze[0].size()){
                        continue;
                    }
                    if(maze[nr][nc]=='+') continue;
                    if(nr==0 || nc==0 || nr==maze.size()-1 || nc==maze[0].size()-1){
                        return dist;
                    }
                    maze[nr][nc]='+';
                    q.push({nr,nc});
                }

            }
        }
        return -1;

    }
};