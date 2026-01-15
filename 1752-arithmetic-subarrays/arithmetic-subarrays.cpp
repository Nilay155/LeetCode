class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans(m,false);
        for(int i = 0 ; i < m ; i++) {
            int s = l[i], e = r[i];
            vector<int> arr;
            for(int k = s ; k <= e ; k++) arr.push_back(nums[k]);

            sort(arr.begin(),arr.end());
            if((int)arr.size() == 1) {
                ans[i] = true;
                continue;
            }
            int cd = arr[1] - arr[0];
            bool flag = true;
            for(int k = 2 ; k < (int)arr.size() ; k++) {
                int diff = arr[k] - arr[k-1];
                if(diff != cd) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans[i] = true;
        }  
        return ans;  
    }
};