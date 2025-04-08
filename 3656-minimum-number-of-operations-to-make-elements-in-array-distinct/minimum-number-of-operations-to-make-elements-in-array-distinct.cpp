class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int repeatedIndex = -1,secondRepeatedIndex = -2;
        unordered_map<int,int> mpp;
        for(int i = n-1 ; i >= 0 ; i--) {
            if(mpp.find(nums[i]) != mpp.end()) {
                repeatedIndex = max(repeatedIndex,i); 
            }
            mpp[nums[i]]=i;
        }

        int k = -1;
        int res = 0;
        while(k < repeatedIndex) {
            k += 3;
            res += 1;
        }
        return res;
    }
};