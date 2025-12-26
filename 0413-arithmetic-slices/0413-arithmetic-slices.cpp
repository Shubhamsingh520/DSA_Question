class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
         
        if(i < 2) return 0; 
        
        if(dp[i] != -1) return dp[i]; 
        
         
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) { 
            dp[i] = 1 + solve(i-1, nums, dp);   
        } else { 
            dp[i] = 0;   
            solve(i-1, nums, dp);   
        } 
        
        return dp[i]; 
    } 

    int numberOfArithmeticSlices(vector<int>& nums) { 
        int n = nums.size(); 
        vector<int> dp(n, -1); 
        int total = 0; 
        
        
        for(int i = 2; i < n; i++) { 
            total += solve(i, nums, dp); 
        } 
        return total; 
    } 
}; 
