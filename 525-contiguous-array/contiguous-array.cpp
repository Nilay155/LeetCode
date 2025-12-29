class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int count = 0, ans = 0;
        
        map<int,int> mpp;
        mpp[0] = -1;
        for(int i = 0 ; i < n ; i++) {
            count += (nums[i] == 1) ? 1 : -1;

            if(mpp.find(count) != mpp.end()) {
                ans = max(ans,i - mpp[count]);
            } else {
                mpp[count] = i;
            }
        }
        return ans;
    }
};