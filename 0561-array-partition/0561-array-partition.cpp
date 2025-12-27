class Solution {
public:
    int solve(int i, vector<int>& nums) {
        if(i >= nums.size()) {
            return 0;
        }
        return nums[i] + solve(i+2, nums);
    }
    int arrayPairSum(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
        return solve(0, nums);
        
    }
};