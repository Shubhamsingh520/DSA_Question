class Solution {
public:
    int fxn(int i, int j, vector<int> &ar) {
        if(i == j) {
            return ar[i];
        }
        int left = ar[i] - fxn(i+1, j, ar);
        int right = ar[j] - fxn(i, j-1, ar);
        return max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int t = fxn(0, n-1, nums);
        return t>=0?true:false;
        
    }
};