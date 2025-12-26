class Solution {
public:
    static const int MAXN = 1005;
    int dp[MAXN][MAXN][4][2];

    int solve(int i, int prev, int taken, vector<int>& rating, bool inc) {
        if(taken == 3) return 1;
        if(i == rating.size()) return 0;

        int pi = prev + 1;  // prev=-1 -> 0
        if(dp[i][pi][taken][inc] != -1)
            return dp[i][pi][taken][inc];

        int count = 0;

        count += solve(i+1, prev, taken, rating, inc);

        if(prev == -1) {
            count += solve(i+1, i, 1, rating, inc);
        }
        else if(taken == 1) {
            if(rating[i] > rating[prev])
                count += solve(i+1, i, 2, rating, true);
            if(rating[i] < rating[prev])
                count += solve(i+1, i, 2, rating, false);
        }
        else if(taken == 2) {
            if(inc && rating[i] > rating[prev])
                count += solve(i+1, i, 3, rating, inc);
            if(!inc && rating[i] < rating[prev])
                count += solve(i+1, i, 3, rating, inc);
        }

        return dp[i][pi][taken][inc] = count;
    }

    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, 0, rating, true);
    }
};

