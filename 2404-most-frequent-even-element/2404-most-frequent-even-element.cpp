class Solution {
public:
    vector<int> res;
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                m[nums[i]]++;
            }
        }
        int maxfreq = 0;
        for(auto &p : m) {
            if(p.second > maxfreq) {
                maxfreq = p.second; 
            }
        }
        for(auto &p : m) {
            if(p.second == maxfreq && maxfreq > 0) {
                res.push_back(p.first);
            }
        }
        if(res.empty()) return -1;
        return *min_element(res.begin(), res.end());
    }
};