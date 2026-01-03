class Solution {
public:
    int solve(vector<int>& nums, int i, int n, int target) {
        if(i == n) {
            return n;
        }
        if(nums[i] >= target) { 
            return i;
        }
        return solve(nums, i+1, n, target);
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, 0, n, target);
    }
};