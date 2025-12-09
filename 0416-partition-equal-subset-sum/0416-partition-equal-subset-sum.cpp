class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;

        int target = total / 2;

        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));

        return solve(nums, target, dp);
    }

    bool solve(vector<int>& nums, int sum, vector<vector<bool>>& dp) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            int val = nums[i - 1];
            for (int j = 1; j <= sum; j++) {
                bool npick = dp[i - 1][j];
                bool pick = false;
                if (val <= j) pick = dp[i - 1][j - val];
                dp[i][j] = pick || npick;
            }
        }

        return dp[n][sum];
    }
};
