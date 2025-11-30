class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max = INT32_MIN;
        int maxIndex = -1; 
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > max) {
                max = arr[i];
                maxIndex = i;
            }
        }
        return maxIndex;
        
    }
};