class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto & p : m) {
            if(p.second % k == 0) {
                res += p.first * p.second;
            }
        }
        return res;
    }
};