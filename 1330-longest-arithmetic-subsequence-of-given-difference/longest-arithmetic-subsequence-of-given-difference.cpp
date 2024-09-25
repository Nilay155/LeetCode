class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int,int> mpp;
        int ans = 1;
        for(int i = 0; i < n ; i++) {

            if(mpp.find(arr[i]-difference) != mpp.end()) {
                ans = max(ans,1 + mpp[arr[i]-difference]);
            }
            mpp[arr[i]] = mpp[arr[i]-difference] + 1;
        }   
        return ans;
    }
};