struct Closest {
    int distsq;
    int idx;
    bool operator<(const Closest& other) const {
        return distsq > other.distsq;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Closest> closest; 

        for(int i=0; i<points.size(); i++) {
            int distsq = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            closest.push_back({distsq, i});
        }

        priority_queue<Closest> pq(closest.begin(), closest.end());

        vector<vector<int>> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(points[pq.top().idx]);
            pq.pop();
        }
        return ans;
        
    }
};