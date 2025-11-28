class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int n = matrix.size();
        int m = matrix[0].size();

        int srow = 0, scol = 0;
        int erow = n-1, ecol = m-1; 

        while(srow <= erow && scol <= ecol) {

            for(int j = scol; j<=ecol; j++) {
                result.push_back(matrix[srow][j]);
            }
            for(int i=srow+1; i<=erow; i++) {
                result.push_back(matrix[i][ecol]);
            }
            for(int j=ecol-1; j>=scol; j--) {
                if(srow == erow) {
                    break;
                }
                result.push_back(matrix[erow][j]);
            }
            for(int i=erow-1; i>=srow+1; i--) {
                if(scol == ecol) {
                    break;
                }
                result.push_back(matrix[i][scol]);
            }
            srow++, scol++;
            erow--, ecol--;
        }
        return result;
        
    }
};