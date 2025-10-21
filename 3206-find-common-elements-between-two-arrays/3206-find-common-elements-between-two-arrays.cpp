class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end()); 
        int count1 = 0, count2 = 0;
        for(int el : nums1) {
            if(s2.find(el) != s2.end()) {
                count1++;
            }
        }
        for(int el : nums2) {
            if(s1.find(el) != s1.end()) {
                count2++;
            }
        }
        return {count1, count2};
    }
};