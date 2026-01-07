class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto &p : m) {
            int x = p.first;
            if(m[x] == 1 && 
                m.find(x-1) == m.end() && m.find(x+1) == m.end()) {
                    res.push_back(x);
            }
        }
        return res;
    }
};
