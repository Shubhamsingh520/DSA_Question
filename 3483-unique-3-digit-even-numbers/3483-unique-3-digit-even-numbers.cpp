class Solution {
public:

    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();
        for(int i=0; i<n; i++) {
            int a = digits[i];
            if(a == 0) {
                continue;
            }
            for(int j=0; j<n; j++) {
                if(j == i) {
                    continue;
                }
                int b = digits[j];
                for(int k=0; k<n; k++) {
                    if(k == i || k == j) {
                        continue;
                    }
                    int c = digits[k];
                    if(c % 2 != 0) {
                        continue;
                    }
                    int number = a*100 + b*10 + c;
                    s.insert(number);
                }
            }
        }
        return s.size();
        
    }
};