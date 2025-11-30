class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        int maxfreq = 0;
        for(auto &p : m) {
            maxfreq = max(maxfreq, p.second);
        }
        int res = 0;
        for(auto &p : m) {
            if(p.second == maxfreq) {
                res += p.second;
            }  
        }
        return res;
        
    }
};