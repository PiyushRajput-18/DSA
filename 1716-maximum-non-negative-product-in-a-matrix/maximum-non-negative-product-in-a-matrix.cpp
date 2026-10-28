class Solution {
public:
    long long dp[15][15][2];
    bool vis[15][15];

    pair<long long, long long> solve(
        int i, int j, vector<vector<int>>& grid
    ) {
        int m = grid.size(), n = grid[0].size();

        if (i == m-1 && j == n-1)
            return {grid[i][j], grid[i][j]};

        if (i >= m || j >= n)
            return {LLONG_MAX, LLONG_MIN};

        if (vis[i][j])
            return {dp[i][j][0], dp[i][j][1]};

        auto down = solve(i+1, j, grid);
        auto right = solve(i, j+1, grid);

        long long x = grid[i][j];
         long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        if (down.first != LLONG_MAX) {
            mx = max(mx, max(down.first*x, down.second*x));
            mn = min(mn, min(down.first*x, down.second*x));
        }

        if (right.first != LLONG_MAX) {
            mx = max(mx, max(right.first*x, right.second*x));
            mn = min(mn, min(right.first*x, right.second*x));
        }

        vis[i][j] = true;
        dp[i][j][0] = mn;
        dp[i][j][1] = mx;

        return {mn, mx};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));

        auto ans = solve(0, 0, grid);

        if (ans.second < 0)
            return -1;

        return ans.second % 1000000007;
    }
};
