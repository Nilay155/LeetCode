class Solution {
private:
    bool check(vector<int> &nums,int mid,int k) {

        int i = 0, j = 1, n = nums.size();
        int count = 0;
        while(i < n && j < n) {

            while(j < n && nums[j] - nums[i] <= mid) j++;
            // at index j now the condition dosent hold true nums[j] - nums[i] <= mid
            if(i < j)
                count += j - i - 1;
            i += 1;
        }

        while(i < n) {
            if(i < j)
                count += j - i - 1;
            i += 1;
        }
        // cout << mid << "  " << count << "   " << k << "\n";
        return count >= k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int l = 0, r = nums[n - 1] - nums[0];

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(check(nums,mid,k)) {
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }

        return l;
    }
};