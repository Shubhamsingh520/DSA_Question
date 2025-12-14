class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) { 
        if(i >= m || j >= n) {
            return 1e9;
        }
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(grid, i, j+1, dp);
        int down  = solve(grid, i+1, j, dp);

        dp[i][j] = grid[i][j] + min(right, down);
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, 0, 0, dp);
    }
};
