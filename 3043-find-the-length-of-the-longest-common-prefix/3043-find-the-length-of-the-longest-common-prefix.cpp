class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;

        for(int i = 0; i < arr1.size(); i++) {
            string s = to_string(arr1[i]);   // FIX
            string temp = "";                // FIX
            for(char c : s) {
                temp += c;
                m1[temp]++;
            }
        }

        for(int i = 0; i < arr2.size(); i++) {
            string s = to_string(arr2[i]);   // OK
            string temp = "";                // FIX
            for(char c : s) {
                temp += c;
                m2[temp]++;
            }
        }

        int ans = 0;
        for(auto &p : m1) {
            if(m2.count(p.first)) {
                ans = max(ans, (int)p.first.length());
            }
        }

        return ans;
    }
};
