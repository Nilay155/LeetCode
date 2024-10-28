class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        map<double,int> mpp;

        for(int num : nums) mpp[double(num)]++;

        int res = -1;
        for(int i = 0 ; i < n ; i++) {

            double num = sqrt(nums[i]);
            int temp = 1;
            
            while(num != 1.00) {
                if(mpp.find(num) != mpp.end()) temp += 1;
                else break;
                num = sqrt(num);
            }
            if(temp > 1) res = max(res,temp);
        }
        return res;
    }
};