class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();

        long long int sum = 0;
        for(int k : nums) sum += k;

        // Not Possible
        if(sum >= m || n > m)
            return -1;

        int l = 1, r = m;
        while(l <= r) {
            int mid = (l + r) >> 1;
   
            vector<int> lastPosition(n,m);
            for(int i = 0 ; i < mid ; i++) {
                int c = changeIndices[i];
                lastPosition[c - 1] = i;
            }

            vector<pair<int,int>> positions;
            for(int i = 0 ; i < n ; i++) 
                if(lastPosition[i] != m)
                    positions.push_back({lastPosition[i],nums[i]});
        
            sort(positions.begin(),positions.end());
            long long int timeConsumed = 0;
            int count = 0;
            for(int i = 0 ; i < (int) positions.size() ; i++) {
                auto [pos,val] = positions[i];
                if(pos + 1 - timeConsumed  > val) {
                    count += 1;
                    timeConsumed += val + 1;
                } else {
                    break;
                }
            }

            if(count >= n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l == m+1 ? -1 : l;

    }
};