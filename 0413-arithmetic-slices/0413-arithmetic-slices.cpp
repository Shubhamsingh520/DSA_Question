class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        // Base case: slices start from index 2 (length 3)
        if(i < 2) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        // Check if nums[i-2], nums[i-1], nums[i] form an arithmetic slice
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            dp[i] = 1 + solve(i-1, nums, dp); // extend previous slices
        } else {
            dp[i] = 0; // no slice ending at i
            solve(i-1, nums, dp); // still compute previous slices
        }
        
        return dp[i];
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int total = 0;
        
        // Compute slices ending at each index
        for(int i = 2; i < n; i++) {
            total += solve(i, nums, dp);
        }
        return total;
    }
};
