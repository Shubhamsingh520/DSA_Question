class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        if(pattern.size() != words.size()) return false;
        unordered_map<char, int> m;
        unordered_map<string, int> t;
        for(int i=0; i<pattern.size(); i++) {
            if(m.find(pattern[i]) == m.end()) {
                m[pattern[i]] = i;
            }
            if(t.find(words[i]) == t.end()) { 
                t[words[i]] = i;
            }
            if(m[pattern[i]] != t[words[i]]) {
                return false;
            }
        }
        return true;
    }
};