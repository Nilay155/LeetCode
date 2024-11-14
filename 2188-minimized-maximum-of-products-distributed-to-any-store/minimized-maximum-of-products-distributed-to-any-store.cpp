class Solution {
    int maxi(vector<int> &nums,int n) {
        int res = 0;
        for(int i = 0 ; i < n ; i++) res = max(res,nums[i]);
        return res;
    }
    
public: 
    int check(vector<int> &nums,int n,int k,int ans) {
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            count += (nums[i]/ans);
            if(nums[i]%ans != 0) count += 1;
        }
        if(ans == 6) cout << count << endl;
        return count <= k;
    }
    int minimizedMaximum(int k, vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = maxi(nums,n);
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;

            if(check(nums,n,k,mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};