class Solution {
public:
    int integerReplacement(int n) {
        vector<long long> dp(10000000, -1); 
        return solve(n, dp);
    }

    long long solve(long long n, vector<long long>& dp) {
        if (n == 1) return 0;

        if (n < dp.size() && dp[n] != -1)
            return dp[n];

        long long ans;

        if (n % 2 == 0) {
            ans = 1 + solve(n / 2, dp);
        } else {
            ans = 1 + min(solve(n + 1, dp), solve(n - 1, dp));
        }

        if (n < dp.size())
            dp[n] = ans;   

        return ans;
    }
};
