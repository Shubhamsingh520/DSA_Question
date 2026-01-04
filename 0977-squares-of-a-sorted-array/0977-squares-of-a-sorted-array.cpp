class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        int i=0;
        int j = n-1;
        int k = n-1;
        while(i <= j) {
            if(abs(nums[i]) > abs(nums[j])) {
                temp[k--] = nums[i] * nums[i];
                i++;
            } else {
                temp[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return temp;
        
    }
};