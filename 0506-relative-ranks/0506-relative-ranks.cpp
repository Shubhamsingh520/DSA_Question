class Solution {
public:
    vector<string>place = {"Gold Medal", "Silver Medal", "Bronze Medal"}; 
    vector<string> findRelativeRanks(vector<int>& score) {
        int sz = score.size();
        vector<string> ans(sz);
        vector<pair<int,int>> p;

        for(int i=0; i<score.size(); i++) {
            p.push_back({score[i], i});
        }
        sort(p.rbegin(), p.rend());
        int k = 0;
        for(int k=0; k<score.size(); k++) {
            if(k<3) {
                ans[p[k].second] = place[k];
            } else {
                ans[p[k].second] = to_string(k + 1);
            }
        }
        return ans;
        
    } 
};