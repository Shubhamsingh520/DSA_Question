class Solution {
public:
    static const int MOD = 1e9 + 7;

    int solve(int n, vector<int>& dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        long long res = (2LL * solve(n-1, dp)) % MOD;
        res = (res + solve(n-3, dp)) % MOD;

        return dp[n] = res;
    }

    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
