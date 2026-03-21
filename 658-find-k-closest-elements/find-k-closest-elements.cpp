class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int l = 0, r = 0,sum = 0;
        int minSum = INT_MAX, index = -1;
        while(r < n) {
            sum += abs(arr[r] - x);

            if(r - l + 1 >= k) {
                // one window of size k is ready
                if(index == -1) {
                    index = l,minSum = sum;
                } else {
                    if(minSum > sum) {
                        index = l, minSum = sum;
                    }
                }
                sum -= abs(arr[l] - x);
                l += 1;
            }
            r += 1;
        }
        return vector<int>(arr.begin() + index,arr.begin() + index + k);
    }
};