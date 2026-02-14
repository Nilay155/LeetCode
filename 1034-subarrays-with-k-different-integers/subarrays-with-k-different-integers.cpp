class Solution {
private:
    int f(vector<int> &nums,int k) {
        int n = nums.size();
        unordered_map<int,int> count;
        int l = 0,r = 0, ans = 0;
        while(r < n) {
            count[nums[r]] += 1;

            while(l <= r && count.size() > k) {
                count[nums[l]] -= 1;
                if(count[nums[l]] == 0)
                    count.erase(nums[l]);
                l += 1;
            } 
            ans += (r - l + 1);
            r += 1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};