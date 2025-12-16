class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int helper(int i, int j, vector<vector<int>>& dungeon) {
        if (i >= n || j >= m) return INT_MAX;

         
        if (i == n - 1 && j == m - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        
        if (dp[i][j] != -1) return dp[i][j];

        int right = helper(i, j + 1, dungeon);
        int down  = helper(i + 1, j, dungeon);

        int need = min(right, down) - dungeon[i][j];

        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        dp.assign(n, vector<int>(m, -1));

        return helper(0, 0, dungeon);
    }
};
