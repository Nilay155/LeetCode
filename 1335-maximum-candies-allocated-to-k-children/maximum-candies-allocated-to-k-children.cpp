class Solution {
private:
    bool check(vector<int> &nums,long long mid,long long k) {
        int n = nums.size();
        long long cnt = 0;

        if(mid == 0) return true;
        for(int i = 0 ; i < n ; i++) {
            cnt += (nums[i]/mid);
        }
        return cnt >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 0;
        long long high = *max_element(candies.begin(),candies.end());
        while(low <= high){
            long long mid = (low + high) >> 1;
            if(check(candies,mid,k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};