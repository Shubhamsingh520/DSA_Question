class Solution {
public:
    vector<vector<int>> dp;
    bool helper(string s, string t, int n, int m) {
        if(n == 0) {
            return true;
        }
        if(m == 0) {
            return false;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(s[n-1] == t[m-1]) {
            return dp[n][m] = helper(s, t, n-1, m-1);
        } else {
            return dp[n][m] = helper(s, t, n, m-1);
        }
    }
    bool isSubsequence(string s, string t) {
        dp.assign(s.size() + 1, vector<int>(t.size() + 1, -1));
        return helper(s, t, s.size(), t.size());
        
    }
};