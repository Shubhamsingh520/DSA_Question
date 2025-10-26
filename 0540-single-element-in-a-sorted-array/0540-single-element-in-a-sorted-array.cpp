class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> m; 
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }

        for(auto& pair : m) {
            if(pair.second == 1) {
                return pair.first; 
            }
        }
        return -1;
        
    }
};