class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        int res = 0;
        for(auto &p : m) {
            if(p.second == 1) {
                res = p.first;
            }
        }
        return res;
        
    }
};