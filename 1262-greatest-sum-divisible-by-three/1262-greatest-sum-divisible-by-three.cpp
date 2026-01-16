class Solution {
public:

    int solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == nums.size()) {
            if(sum % 3 == 0) {
                return sum;
            }
            return INT_MIN;
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
         
        int inc = solve(i+1, (sum+nums[i])%3, nums, dp);
        if (inc != INT_MIN)
            inc += nums[i];
        int exc = solve(i+1, sum, nums, dp);
        dp[i][sum] = max(inc, exc);
        return dp[i][sum]; 
         
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return solve(0, 0, nums, dp); 
    }
};