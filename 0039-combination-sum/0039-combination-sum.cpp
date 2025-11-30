class Solution {
public:
    set<vector<int>> s;
    void getAllcombination(vector<int>& candidates, int idx, int target, vector<vector<int>> &ans, vector<int> &combin) {
        if(idx == candidates.size() || target < 0) {
            return;
        }

        if(target == 0) {
            if(s.find(combin) == s.end()) {
            ans.push_back(combin);
            s.insert(combin);
            }
            return;
        }
        combin.push_back(candidates[idx]);
        //single
        getAllcombination(candidates, idx+1, target-candidates[idx], ans, combin);
        //multiple
        getAllcombination(candidates, idx, target-candidates[idx], ans, combin);
        combin.pop_back();

        //exclusion
        getAllcombination(candidates, idx+1, target, ans, combin);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllcombination(candidates, 0, target, ans, combin);
        return ans;
    }
};