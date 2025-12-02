class Solution {
public:

    int robhelper(int i, int n, vector<int>& nums, vector<int>& dp) { 
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) { 
            return dp[i];
        }
        int inc = nums[i] + robhelper(i+2, n, nums, dp);
        int exc = 0 + robhelper(i+1, n, nums, dp);
        return dp[i] = max(inc, exc);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robhelper(0, n, nums, dp); 
        
    }
};