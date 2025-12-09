class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, target, nums, dp);
    }

    bool solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (i >= nums.size() || sum < 0) return false;

        if (dp[i][sum] != -1) return dp[i][sum];

        bool pick = solve(i + 1, sum - nums[i], nums, dp);
        bool npick = solve(i + 1, sum, nums, dp);

        return dp[i][sum] = (pick || npick);
    }
};
