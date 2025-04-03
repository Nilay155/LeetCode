class Solution {
private:
    long long func(vector<int> &nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];

        for(int i = 1 ; i < n ; i++) {
            left[i] = max(nums[i],left[i-1]);
            right[n-i-1] = max(nums[n-i-1],right[n-i]);
        }

        long long ans = 0;
        for(int i = 1; i < n-1 ; i++) {
            int leftMax = left[i-1];
            int rightMax = right[i+1];
            // cout << leftMax << "  " << nums[i] << "  " << rightMax << endl;
            ans = max(ans,(leftMax-nums[i])*1LL*rightMax);
        }
        return ans;
    }
public:
    long long maximumTripletValue(vector<int>& nums) {
        // int n = nums.size();
        // long long ans = 0;

        // int mini1 = n-1, mini2 = n-1;
        // int maxi1 = n-2, maxi2 = n-2;

        // for(int i = n-3; i >= 0 ; i--) {
        //     ans = max(ans,(nums[i]-nums[mini1])*1LL*nums[maxi1]);

        //     if(nums[i] > nums[maxi1]) {
        //         if(i < mini1) {
        //             maxi1 = i;
        //         }
        //     }
        //     if(nums[i] < nums[mini1]) {

        //     }
        // }
        return func(nums);
    }
};