class Solution {
private:
    bool check(vector<int> &nums,int k,int capacity) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            if(sum + nums[i] <= capacity) {
                sum += nums[i];
            } else {
                k -= 1;
                sum = nums[i];
                if(sum > capacity) return false;
            }
        }
        k -= 1;
        return k >= 0;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        
        int totalSum = 0;
        for(int n : nums) totalSum += n;

        int s = 0, e = totalSum;
        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(check(nums,k,mid)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};