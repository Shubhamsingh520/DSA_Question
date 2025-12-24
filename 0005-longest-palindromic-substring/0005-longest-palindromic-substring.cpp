class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int ans = 1;
    int start = 0;

    bool isPal(int i, int j, string &s) {
        if (i >= j) return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j] && isPal(i + 1, j - 1, s)) {
            if (j - i + 1 > ans) {
                ans = j - i + 1;
                start = i;
            }
            return dp[i][j] = 1;
        }

        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        n = s.size();
        if (n == 0) return "";

        dp.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                isPal(i, j, s);
            }
        }

        return s.substr(start, ans);
    }
};
