class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i = 0;
        while(i < n && nums[i] == 1) i++;
        ans = max(ans,(i % 2 == 0 ? i-1 : i));

        unordered_map<long long,int> mpp;
        for(int j = i ; j < n ; j++) {
            mpp[nums[j]] += 1;
        }

        for(int j = i ; j < n ; j++) {
            long long number = nums[j];
            int len = 0;
            while(mpp.find(number) != mpp.end()) {
                if(mpp[number] > 1) {
                    number *= number;
                    len += 2;
                } else {
                    len += 1;
                    break;
                }
            } 
            if(len % 2 == 0) {
                ans = max(ans,len - 1);
            } else {
                ans = max(ans,len);
            }
        }
        return ans;
    }
};