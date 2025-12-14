class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        if(i >= m || j >= n) {
            return 0;
        }
        if(obstacleGrid[i][j] == 1) {
            return 0;
        }
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int right = solve(obstacleGrid, i, j+1, dp);
        int down = solve(obstacleGrid, i+1, j, dp);
        dp[i][j] = right + down;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, 0, 0, dp);
        
    }
};