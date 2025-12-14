class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& matrix, int i, int j) {
        
        if (j < 0 || j >= n) return INT_MAX;

         
        if (i == n - 1) return matrix[i][j];

         
        if (dp[i][j] != INT_MAX) return dp[i][j];

         
        int down       = solve(matrix, i + 1, j);
        int downLeft   = solve(matrix, i + 1, j - 1);
        int downRight  = solve(matrix, i + 1, j + 1);

        return dp[i][j] = matrix[i][j] + min({down, downLeft, downRight});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp = vector<vector<int>>(n, vector<int>(n, INT_MAX));

        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, solve(matrix, 0, j));
        }
        return result;
    }
};
