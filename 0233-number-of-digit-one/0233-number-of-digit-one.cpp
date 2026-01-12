class Solution {
public:
    int solve(int i, bool rest, int cnt, string &s,
              vector<vector<vector<int>>>& dp) {

        if (i == s.size()) {
            return cnt;
        }

        if (dp[i][rest][cnt] != -1) {
            return dp[i][rest][cnt];
        }

        int ub = rest ? s[i] - '0' : 9;
        int res = 0;

        for (int digit = 0; digit <= ub; digit++) {
            res += solve(
                i + 1,
                rest && (digit == ub),
                cnt + (digit == 1),
                s,
                dp
            );
        }

        return dp[i][rest][cnt] = res;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        int len = s.size();

        vector<vector<vector<int>>> dp(
            len,
            vector<vector<int>>(2, vector<int>(len, -1))
        );

        return solve(0, 1, 0, s, dp);
    }
};
