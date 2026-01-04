class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            vector<int> divs;

            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    divs.push_back(i);
                    if (i != x / i)
                        divs.push_back(x / i); 
                }
            }

            if (divs.size() == 4) {
                int sum = 0;
                for (int d : divs)
                    sum += d;
                ans += sum;
            }
        }
        return ans;
    }
};
