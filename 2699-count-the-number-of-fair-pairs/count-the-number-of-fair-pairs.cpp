#define ll long long
class Solution {
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ll res = 0;
        for(int i = 0 ; i < n ; i++) {
            int ele = nums[i];

            // finding lower Bound
            int start = i+1;
            int end = n-1;
            int x = -1;
            while(start <= end) {
                int mid = (start + end) >> 1;
                if(nums[mid] + ele >= lower) {
                    end = mid-1;
                    x = mid;
                } else {
                    start = mid+1;
                }
            }
            // finding UpperBound
            int low = i+1;
            int high = n-1;
            int y = n;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(nums[mid] + ele > upper) {
                    high = mid-1;
                    y = mid;
                } else {
                    low = mid+1;
                }
            }
            if(x == -1) continue;
            res += (y-x);
        }
        return res;
    }
};