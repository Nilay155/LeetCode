class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        map<int,int> freq;
        for(int i = 0 ; i < n ; i++) {
            freq[trips[i][1]] += trips[i][0];
            freq[trips[i][2]] -= trips[i][0]; 
        }
        int count = 0;

        for(auto [time,cnt] : freq) {
            count += cnt;
            if(count > capacity) return false;
        }
        return count <= capacity;
    }
};