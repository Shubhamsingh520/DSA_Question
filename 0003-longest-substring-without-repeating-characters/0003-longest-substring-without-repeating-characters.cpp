class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            unordered_set<char> S;
            for(int j=i; j<s.size(); j++) {
                if(S.count(s[j])) break;
                S.insert(s[j]);
                ans = max(ans, j-i+1);
            }
        }
        return ans;
        
    }
};