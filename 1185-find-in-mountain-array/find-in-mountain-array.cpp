/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int findIndex1(MountainArray & mountainArr,int low,int high,int target) {
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;

            if(mountainArr.get(mid) == target) {
                ans = mid;
                high = mid-1;
            } else if(mountainArr.get(mid) > target){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
    int findIndex2(MountainArray& mountainArr,int low,int high,int target) {
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;

            if(mountainArr.get(mid) == target) {
                ans = mid;
                high = mid-1;
            } else if(mountainArr.get(mid) < target){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
 public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int low = 0, high = n-1;

        while(low < high) {
            int mid = (low + high) >> 1;

            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }
        int res1 = findIndex1(mountainArr,0,low,target);
        int res2 = -1;
        if(res1 != -1) {
            return res1;
        } else {
            res2 = findIndex2(mountainArr,high,n-1,target);
        }
        return res2;

    }
};