class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int>& nums, int start) {
        if (path.size() >= 2) {
            result.push_back(path);
        }

        unordered_set<int> s;  

        for (int i = start; i < nums.size(); i++) {
            
            if (!path.empty() && nums[i] < path.back()) {
                continue;
            }

            if (s.count(nums[i])) {
                continue;
            }

            s.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};
