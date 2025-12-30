class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1; i < n; i++){
            int withoutBreak = i * (n - i);      
            int withBreak = i * solve(n - i, dp);    
            ans = max({ans, withoutBreak, withBreak});
        }
        dp[n] = ans;
        return ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
