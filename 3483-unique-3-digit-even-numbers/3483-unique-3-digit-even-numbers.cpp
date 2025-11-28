class Solution {
public:

    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    if(i != j && j != k && i != k) {
                        if(digits[i] != 0) {
                            if(digits[k] % 2 == 0) {
                                int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                                s.insert(number);
                            }
                        }
                    }
                }
            }
        }
        return s.size();
        
    }
};