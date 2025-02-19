class Solution {
private:
    int binarySearch(vector<int> &nums,int low,int high) {
        
        while(low < high) {
            int mid = (low + high) >> 1;

            if(nums[mid] < nums[mid+1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }  
        return low;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        return binarySearch(arr,0,n-1);
    }
};