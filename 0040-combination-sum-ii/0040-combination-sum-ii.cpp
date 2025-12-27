class Solution {
public:
    void backtrack(vector<int>& cand, int start, int target,
                   vector<int>& path, vector<vector<int>>& res) {
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = start; i < cand.size(); i++){
            if(i > start && cand[i] == cand[i-1]) continue;
            if(cand[i] > target) break;

            path.push_back(cand[i]);
            backtrack(cand, i + 1, target - cand[i], path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;                
        backtrack(candidates, 0, target, path, res); 
        return res;
    }
};


