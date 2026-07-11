class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int d = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == m - 1 && c == n - 1)
                return d;

            if (d > effort[r][c])
                continue;

            for (auto [dr, dc] : dir) {

                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int edge =
                    abs(heights[r][c] - heights[nr][nc]);

                int newEffort =
                    max(d, edge);

                if (newEffort < effort[nr][nc]) {

                    effort[nr][nc] = newEffort;

                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return 0;
    }
};