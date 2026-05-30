class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int smallestDiff = 1e9, closestSum;

        for(int i = 0 ; i < n - 2 ; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > target) {
                    if(sum - target < smallestDiff) {
                        smallestDiff = sum - target;
                        closestSum = sum;
                    }
                    k--;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                } else {
                    if(target - sum < smallestDiff) {
                        smallestDiff = target - sum;
                        closestSum = sum;
                    }
                    j++;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                }
            }
        }
        return closestSum;
    }
};