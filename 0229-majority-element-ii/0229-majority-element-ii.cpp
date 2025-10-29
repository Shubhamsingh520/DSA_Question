class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto & p : m) {
            if(p.second > (nums.size()) / 3) {
                res.push_back(p.first);
            }
        }
        return res;
        
    }
};