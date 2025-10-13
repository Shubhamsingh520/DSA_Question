class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push({nums[i], i});
        }

        vector<pair<int, int>> topK; 
        for(int i=0; i<k; i++) {
            topK.push_back(pq.top());
            pq.pop();
        }
            sort(topK.begin(), topK.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        });

        vector<int> result;
        for(int i=0; i<topK.size(); i++) { 
            result.push_back(topK[i].first);
        }
        return result;
        
    }
};