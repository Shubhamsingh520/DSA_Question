struct Row {
    int count;
    int idx;

    Row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    bool operator<(const Row& other) const {
        if (count == other.count)
            return idx > other.idx;
        return count > other.count;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Row> rows;

        for(int i=0; i<mat.size(); i++) {
            int count = 0;
            for(int j=0; j<mat[i].size() && mat[i][j] == 1; j++) { 
                count++;
            }
            rows.push_back(Row(count, i));
        }

        priority_queue<Row, vector<Row>> pq(rows.begin(), rows.end()); 

        vector<int> result;
        for(int i=0; i<k; i++) {
            result.push_back(pq.top().idx);
            pq.pop();
        }
        return result;
        
    }
};