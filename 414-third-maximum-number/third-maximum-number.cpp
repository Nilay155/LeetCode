class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        // k = 3
        long long fm = LLONG_MIN, sm = LLONG_MIN, tm = LLONG_MIN;

        for(int i = 0 ; i < n ; i++) {

            long long num = nums[i];

            if(num > fm) {
                
                // second becomes third
                tm = sm;
                // first beceoms second
                sm = fm;
                // first becomes current
                fm = num;
            } else if(num > sm && num != fm) {
                // second becomes third
                tm = sm;
                // second becomes current
                sm = num;
            } else if(num > tm && num != sm && num != fm) {
                tm = num;
            }
        }
        if(tm == LLONG_MIN) return max(fm,sm);
        return (int)tm;
    }
};