class Solution {
public:
    int n, m;
    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i<0 || i>=n || j<0 || j>=m) {
            return;
        }
        if(board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        n = board.size();
        m = board[0].size();
        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0,  board);
            }
            if(board[i][m-1] == 'O') {
                dfs(i, m-1, board);
            }
        }
        for(int i=1; i<m; i++) {
            if(board[0][i] == 'O') {
                dfs(0, i, board);
            }
            if(board[n-1][i] == 'O') {
                dfs(n-1, i, board);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};