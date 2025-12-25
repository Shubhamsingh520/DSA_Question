class Solution {
public:
    vector<vector<pair<int,int>>> dp; 

    pair<int,int> solve(int i, int prev, vector<int>& nums) {
        if(i == nums.size()) {
            return {0, 1};  
        }

        if(dp[i][prev+1].first != -1) {
            return dp[i][prev+1];
        }

        pair<int,int> incl = {0,0}, excl = {0,0};

         
        if(prev == -1 || nums[i] > nums[prev]) {
            auto p = solve(i+1, i, nums);
            incl = {p.first + 1, p.second};
        }

         
        excl = solve(i+1, prev, nums);

         
        if(incl.first > excl.first) {
            dp[i][prev+1] = incl;
        } else if(excl.first > incl.first) {
            dp[i][prev+1] = excl;
        } else {
             
            dp[i][prev+1] = {incl.first, incl.second + excl.second};
        }

        return dp[i][prev+1];
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<pair<int,int>>(n+1, {-1,0}));

        auto ans = solve(0, -1, nums);
        return ans.second;
    }
};
