class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int lb = 1, maxi = 1;
        for(int i = 1 ; i < n ; i++) {

            if(arr[i] - lb > 1) {
                lb = lb + 1;
                maxi = max(maxi,lb);
            } else {
                lb = arr[i];
                maxi = max(maxi,arr[i]);
            }
        }
        return maxi;
    }
};