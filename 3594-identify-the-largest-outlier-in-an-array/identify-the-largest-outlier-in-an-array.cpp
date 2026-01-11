class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> map;
        unordered_map<int,int> count;

        int sum = 0;
        for(int x : nums) {
            map[2*x] = true;
            count[x] += 1;
            sum += x;
        }
        int ans = -1001;
        for(int i = 0 ; i < n ; i++) {
            int rem = (sum - nums[i]);
            if(map.find(rem) != map.end()) {
                if(rem == 2*nums[i]) {
                    if(count[nums[i]] > 1) 
                        ans = max(ans,nums[i]);
                } else {
                    ans = max(ans,nums[i]);
                }
            }
        }
        return ans;
    }
};