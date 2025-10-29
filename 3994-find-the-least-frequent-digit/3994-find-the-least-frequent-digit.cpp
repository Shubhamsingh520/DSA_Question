class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> m;
        while(n > 0) {
            m[n % 10]++;
            n /= 10;   
        }
        int res = -1;
        int minfreq = INT_MAX;
        for(auto &p : m) {
            if(p.second < minfreq || (p.second == minfreq && p.first < res)) {
                minfreq = p.second;
                res = p.first;
            }
        }
        return res;
        
    }
};