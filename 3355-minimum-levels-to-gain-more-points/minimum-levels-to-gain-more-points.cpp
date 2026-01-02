class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();

        vector<int> prefix(n), suffix(n);
        prefix[0] = (possible[0] == 0) ? -1 : 1;
        suffix[n-1] = (possible[n-1] == 0) ? -1 : 1;

        for(int i = 1 ; i < n ; i++) {
            prefix[i] = ((possible[i] == 0) ? -1 : 1) + prefix[i-1];
            suffix[n-i-1] = ((possible[n-i-1] == 0) ? -1 : 1) + suffix[n-i];
        }

        int ans = INT_MAX;
        for(int i = 0 ; i < n-1 ; i++) {
            // cout << prefix[i] << "  " << suffix[i+1] << "\n";
            if((prefix[i]) > (suffix[i+1])) {
                return i+1;
            }
        }
        return -1;
    }
};