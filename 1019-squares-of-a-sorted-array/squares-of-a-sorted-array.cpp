class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int neg = -1, pos = n;
        for(int i = 0 ; i < n ; i++) {

            if(nums[i] < 0) neg = max(neg,i);
            else pos = min(i,pos);
        }

        while(neg != -1 || pos != n) {
            if(neg != -1 && pos != n) {
                // compare
                if(nums[neg]*nums[neg] >= nums[pos]*nums[pos]) {
                    ans.push_back(nums[pos]*nums[pos]);
                    pos++;
                } else {
                    ans.push_back(nums[neg]*nums[neg]);
                    neg--;
                }
            } else if(neg == -1) {
                ans.push_back(nums[pos]*nums[pos]);
                pos++;
            } else {
                ans.push_back(nums[neg]*nums[neg]);
                neg--;
            }
        }
        return ans;
    }
};