class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 0;

        int maxi = nums[0];
        int mini = nums[0];

        int ans = 0;

        while (j < n) {

            maxi = max(maxi, nums[j]);
            mini = min(mini, nums[j]);

            while (abs(maxi - mini) > 1) {
                i++;

                mini = INT_MAX;
                maxi = INT_MIN;

                for (int k = i; k <= j; k++) {
                    mini = min(mini, nums[k]);
                    maxi = max(maxi, nums[k]);
                }
            }

            if (abs(maxi - mini) == 1) {
                ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;
    }
};
