class Solution {
public:
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,
             int r, int c, int pr, int pc) {

        vis[r][c] = 1;

        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

          
            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size())
                continue;

            if (grid[nr][nc] != grid[r][c])
                continue;


            if (nr == pr && nc == pc)
                continue;

       
            if (vis[nr][nc])
                return true;

            if (dfs(grid, vis, nr, nc, r, c))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, vis, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};