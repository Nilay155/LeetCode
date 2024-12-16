class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b) {
        return a[1] < b[1];
    } 
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());

        vector<int> arr(n);
        int maxi = 0;
        for(int i = n-1 ; i >= 0 ; i--) {
            maxi = max(maxi,events[i][2]);
            arr[i] = maxi;
        }

        // Searching for the index such that curr-i-endTime < goal-j-startTime
        // Searching -> Linear Search -> Brute Force
        // Searching -> Binary Search -> Optimal Solution
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            int val = events[i][2];

            int startTime = events[i][0];
            int endTime = events[i][1];

            int low = i+1;
            int high = n-1;

            while(low <= high) {
                int mid = (low + high) >> 1;

                if(events[mid][0] > endTime) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }

            if(low != n) val += arr[low];

            ans = max(ans,val);
        }
        return ans;
    }
};