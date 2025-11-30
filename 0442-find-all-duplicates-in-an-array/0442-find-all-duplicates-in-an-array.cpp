class Solution {
public:
    vector<int> res;
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto& p : m) {
            if(p.second > 1) {
                res.push_back(p.first);
            }
        }
        return res;
        
    }
};