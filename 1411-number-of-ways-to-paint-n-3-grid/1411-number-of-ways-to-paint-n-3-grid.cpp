class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<long long>> dp;
    long long solve(int row, int n, int type) {
        if (row == 1) {
            return (type == 0) ? 6 : 6;
        }

        if (dp[row][type] != -1)
            return dp[row][type];

        long long same = solve(row - 1, n, 0);
        long long diff = solve(row - 1, n, 1);

        long long ans;
        if (type == 0) {
            
            ans = (same * 3 + diff * 2) % mod;
        } else {
             
            ans = (same * 2 + diff * 2) % mod;
        }

        return dp[row][type] = ans;
    }

    int numOfWays(int n) {
        dp.assign(n + 1, vector<long long>(2, -1));

        long long same = solve(n, n, 0);
        long long diff = solve(n, n, 1);

        return (same + diff) % mod;
    }
};
