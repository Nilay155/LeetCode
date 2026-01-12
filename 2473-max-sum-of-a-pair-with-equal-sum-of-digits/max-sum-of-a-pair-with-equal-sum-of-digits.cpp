class Solution {
private:
    int ds(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mpp;

        for(int i = 0 ; i < n ; i++) {
            int digitsSum = ds(nums[i]);
            if(mpp.find(digitsSum) != mpp.end()) {
                if(mpp[digitsSum].size() <= 1) {
                    mpp[digitsSum].push_back(nums[i]);
                } else {
                    int a = mpp[digitsSum][0], b = mpp[digitsSum][1], c = nums[i];
                    if(a >= c && b >= c) mpp[digitsSum] = {a,b};
                    else if(b >= a && c >= a) mpp[digitsSum] = {b,c};
                    else mpp[digitsSum] = {a,c};
                }
            } else {
                mpp[digitsSum].push_back(nums[i]);
            }
        }
        int ans = -1;
        for(auto [ds,arr] : mpp) {
            if(arr.size() >= 2) {
                ans = max(ans,arr[0] + arr[1]);
            }
        }
        return ans;
    }
};