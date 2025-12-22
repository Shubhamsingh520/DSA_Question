class Solution {
public:
    bool helper(string s, string t, int n, int m) {
        if(n == 0) {
            return true;
        }
        if(m == 0) {
            return false;
        }
        if(s[n-1] == t[m-1]) {
            return helper(s, t, n-1, m-1);
        } else {
            return helper(s, t, n, m-1);
        }
    }
    bool isSubsequence(string s, string t) {
        return helper(s, t, s.size(), t.size());
        
    }
};