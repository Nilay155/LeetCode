class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b) {
        if(a[1] < b[1]) return true;
        else return false;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> nums;
        for(int i = 0 ; i < n ; i++) {
            nums.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(nums.begin(),nums.end(),cmp);

        map<int,int> mpp;
        mpp[0] = 0;

        for(int i = 0 ; i < n ; i++) {
            int start = nums[i][0];
            int end = nums[i][1];
            int value = nums[i][2];
            
            // cout << start << " " << end << endl;
            auto itr = mpp.upper_bound(start);
            
            if (itr != mpp.begin()) {
                --itr;  // Move to the largest key ≤ start
            } else {
                itr = mpp.end();  // No key ≤ start exists
            }
            mpp[end] = max(mpp[end],value + itr->second);
            // cout << itr -> first << " " << start << endl;

            itr = mpp.lower_bound(end);
            if(itr != mpp.begin()) {
                --itr;
            } else {
                itr = mpp.end();
            }
            mpp[end] = max(mpp[end],mpp[itr->first]);

        }

        int ans = 0;
        for(auto& it : mpp) {
            ans = max(ans,it.second);
        }
        return ans;
    }
};