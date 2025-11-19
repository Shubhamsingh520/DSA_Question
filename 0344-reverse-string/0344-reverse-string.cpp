class Solution {
public:
     
    void reverseString(vector<char>& s) {
        stack<char> S; 
        for(int i=0; i<s.size(); i++) {  
            S.push(s[i]); 
        }
        int i=0;
        while(!S.empty()) {
            s[i++] = S.top(); 
            S.pop();
        }  
         
    }        
};