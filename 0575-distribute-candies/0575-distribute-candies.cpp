class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min((int)s.size(), n/2);
    }
};