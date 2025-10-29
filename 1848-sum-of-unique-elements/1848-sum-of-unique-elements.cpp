class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<nums.size(); ) {
            int j = i+1;
            while(j<nums.size() && nums[j] == nums[i]) j++; 
            if(j-i == 1) 
                sum += nums[i];
            i = j;
            
        }
        return sum;
        
    }
};