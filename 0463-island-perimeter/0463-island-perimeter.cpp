class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int r = grid.size();
        int c = grid[0].size();

        if (i < 0 || j < 0 || i >= r || j >= c)
            return 1;

        if (grid[i][j] == 0)
            return 1;

        if (grid[i][j] == 2)
            return 0;

      
        grid[i][j] = 2;

        return dfs(grid, i - 1, j) +
               dfs(grid, i + 1, j) +
               dfs(grid, i, j - 1) +
               dfs(grid, i, j + 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }
};