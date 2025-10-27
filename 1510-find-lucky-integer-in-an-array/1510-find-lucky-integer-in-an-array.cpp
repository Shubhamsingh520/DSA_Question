class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i=0; i<arr.size(); i++) {
            m[arr[i]]++;
        }
        int res = -1;
        for(auto& p : m) {
            if(p.first == p.second) {
                res = max(res, p.first);
            }
        }
        return res;
        
    }
};