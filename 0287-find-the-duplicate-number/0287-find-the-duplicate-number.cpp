class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int x : nums) {
            m[x]++;
            if(m[x] > 1) {
                return x;
            }

        }
        return -1;
    }
};