class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s; 
        int dupli = -1, miss = -1;
        for(int num : nums) {
            if(s.count(num)) {
                dupli = num;
            }
            s.insert(num);
        }
        for(int i=1; i<=n; i++) {
            if(!s.count(i)) {
                miss = i;
                break;
            }
        }
        return {dupli, miss};
    }
};