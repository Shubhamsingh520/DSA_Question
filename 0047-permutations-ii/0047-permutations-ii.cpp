class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
    void backtrack(vector<int>& nums, int st, vector<vector<int>>& result) {
        if(st == nums.size()) {
            result.push_back(nums);
            return; 
        }

        unordered_set<int> s;

        for(int i = st; i<nums.size(); i++) {
            if(s.count(nums[i])) {
                continue;
            }
            s.insert(nums[i]);
            swap(nums[st], nums[i]);
            backtrack(nums, st+1, result);
            swap(nums[st], nums[i]);
        }
    }
};