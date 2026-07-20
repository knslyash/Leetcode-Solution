class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;
        k %= total; 

        vector<vector<int>> result(rows, vector<int>(cols));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int index = r * cols + c;
                int newIndex = (index + k) % total;
                int newR = newIndex / cols;
                int newC = newIndex % cols;
                result[newR][newC] = grid[r][c];
            }
        }

        return result;
    }
};