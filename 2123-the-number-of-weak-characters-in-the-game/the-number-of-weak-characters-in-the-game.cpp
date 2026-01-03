class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(),properties.end(),[&](vector<int> &a,vector<int> &b) {
            if(a[0] == b[0]) return a[1] < b[1];
            else return a[0] > b[0];
        });

        int maxi = 0, count = 0;
        for(int i = 0 ; i < n ; i++) {
            int x = properties[i][0];
            int y = properties[i][1];
            if(maxi > y) count += 1;
            else maxi = y;
        }
        return count;
    }
};