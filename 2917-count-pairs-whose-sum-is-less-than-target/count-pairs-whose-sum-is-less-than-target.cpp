class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        int pairs = 0;
        for(int i = 0 ; i < n ; i++) {

            int s = i + 1 , e = n - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(nums[i] + nums[mid] < target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            pairs += e + 1;
        }
        pairs = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i + 1 ; j < n ; j++) {
                if(nums[i] + nums[j] < target)
                    pairs += 1;
            }
        }
        return pairs;
    }
};