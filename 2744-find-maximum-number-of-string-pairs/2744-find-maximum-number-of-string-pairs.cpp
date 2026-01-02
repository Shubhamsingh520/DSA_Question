class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> m;
        int count = 0;
        for(int i=0; i<words.size(); i++) {
            string s = words[i];
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(m.find(rev) != m.end()) {
                count++;
            } else {
                m[s]++;
            }
        }
        return count;
        
    }
};