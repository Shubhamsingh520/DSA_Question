class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for(int el : nums2) {
            if(s.find(el) != s.end()) {
                res.push_back(el);
                s.erase(el);
            }
        }
        return res;
    }
};