class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int index, vector<int>& nums, vector<int>& current) {
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }
        backtrack(index+1, nums, current);
        current.push_back(nums[index]);
        backtrack(index+1, nums, current);
        current.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(0, nums, current);
        return ans;

    }
};