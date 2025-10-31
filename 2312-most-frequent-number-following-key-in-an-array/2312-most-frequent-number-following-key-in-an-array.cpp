class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> m;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == key) {
                m[nums[i+1]]++; 
            }
        }
        int res = 0;
        int maxcount = 0;
        for(auto &p : m) {
            if(p.second > maxcount) {
                maxcount = p.second;
                res = p.first;
            }
        }
        return res;
        
    }
};