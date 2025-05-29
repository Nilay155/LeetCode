class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int s = 0, e = n-1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            if(arr[mid]-(mid+1) < k) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return (k+e+1);
    }
};