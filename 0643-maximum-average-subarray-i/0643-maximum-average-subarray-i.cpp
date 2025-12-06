class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxsum = INT_MIN;
        int prevsum = 0;
        for(int i=0; i<k; i++) {
            prevsum += nums[i];
        }
        maxsum = prevsum;
        int i=1;
        int j = k;
        while(j<nums.size()) {
            prevsum += nums[j] - nums[i-1];
            maxsum = max(maxsum, prevsum);
            i++;
            j++;
        }
        return (double)maxsum/k;
        
    }
};