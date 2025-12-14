class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }

    bool helper(int i, vector<int>& nums, vector<int>& dp) {  
        if(i >= nums.size()-1) {
            return true;
        }
        if(nums[i] == 0) {
            return false;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        for(int k=1; k<=nums[i]; k++) {
            if(helper(i+k, nums, dp)) { 
                return dp[i] = true;
            }
        }
        return dp[i] = false;

    }
};