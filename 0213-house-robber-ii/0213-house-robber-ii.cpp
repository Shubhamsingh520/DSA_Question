class Solution { 
public:
    int solve(vector<int>& nums, int st, int end) {
        int prev1 = 0, prev2 = 0;
        for(int i=st; i<=end; i++) {
            int inc = nums[i] + prev2;
            int exc = prev1;
            int curr = max(inc, exc);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int pick = solve(nums, 0, n-2); 
        int npick = solve(nums, 1, n-1);
        return max(pick, npick);
    } 
};