class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();

        long long int sum = 0;
        for(int k : nums) sum += k;

        // Not Possible
        if(sum >= m || n > m)
            return -1;
        
        for(int s = 1 ; s <= m ; s++) {
            // cout << 1 << "\n";
            vector<int> lastPosition(n,m);
            for(int i = 0 ; i < s ; i++) {
                int c = changeIndices[i];
                lastPosition[c - 1] = i;
            }

            vector<pair<int,int>> positions;
            for(int i = 0 ; i < n ; i++) 
                if(lastPosition[i] != m)
                    positions.push_back({lastPosition[i],nums[i]});
            
            if(positions.size() < n || sum + n > s)
                continue;
            sort(positions.begin(),positions.end());
            long long int timeConsumed = 0, count = 0;
            for(int i = 0 ; i < (int) positions.size() ; i++) {
                auto [pos,val] = positions[i];
                if(pos + 1 - timeConsumed  > val) {
                    count += 1;
                    timeConsumed += val + 1;
                } else {
                    break;
                }
            }

            if(count == n)
                return s;
        }
        return -1;

    }
};