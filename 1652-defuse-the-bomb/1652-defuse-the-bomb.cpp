class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if(k==0) return ans;
        int sum = 0;
        int st, end;
        if(k>0) {
            st =1;
            end = k;
        } else {
            st = n+k;
            end = n-1;
        }
        for(int i=st; i<=end; i++) {
            sum += code[i%n];
        }
        for(int i=0; i<n; i++) {
            ans[i] = sum;
            sum -= code[(st+i)%n];
            sum += code[(end+i+1)%n];
        }
        return ans;
        
    }
};