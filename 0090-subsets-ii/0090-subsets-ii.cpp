class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int start, vector<int>& nums, vector<int> & current) {
        res.push_back(current);
        unordered_set<int> s;
        for(int i = start; i<nums.size(); i++) {
            if(s.count(nums[i])) {
                continue;
            }
            s.insert(nums[i]);
            current.push_back(nums[i]);    
            backtrack(i+1, nums, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        backtrack(0, nums, current);
        return res;
    }
};