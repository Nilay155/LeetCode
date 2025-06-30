class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mpp;
        for(int num : nums) mpp[num]++;
        
        int maxi = 0;
        for(auto& it : mpp) {
            if(mpp.find(it.first-1) != mpp.end()) {
                maxi = max(maxi,mpp[it.first-1] + it.second);
            }
            if(mpp.find(it.first+1) != mpp.end()) {
                maxi = max(maxi,mpp[it.first+1] + it.second);
            }
        }
        return maxi;
    }
};