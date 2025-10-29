class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto & p : m) {
            if(p.second == 1) {
                res += p.first;
            }
        }
        return res;
    }
};