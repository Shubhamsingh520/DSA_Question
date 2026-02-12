class Solution {
public:
    int n, m, oldcolor, newcolor;
    void dfs(int i, int j, vector<vector<int>>& image) {
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(image[i][j] != oldcolor) return;
        image[i][j] = newcolor;
        dfs(i-1, j, image);
        dfs(i+1, j, image);
        dfs(i, j-1, image);
        dfs(i, j+1, image); 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.empty()) return image;
        n = image.size();
        m = image[0].size();
        oldcolor = image[sr][sc];
        newcolor = color;
        if(oldcolor == newcolor) return image;
        dfs(sr, sc, image);
        return image;
    } 
};
