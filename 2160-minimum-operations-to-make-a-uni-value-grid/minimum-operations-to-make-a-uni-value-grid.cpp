class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        int rem = -1;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int temp = grid[i][j]%x;
                if(rem == -1) rem = temp;
                else {
                    if(rem != temp) return -1;
                }
            }
        }

        // all are giving same remainders
        vector<int> arr;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());  
        int mid = arr.size()/2;

        int mini = 0;
        for(int i = 0 ; i < arr.size() ; i++) {
            if(arr[mid] == arr[i]) continue;
            mini += abs(arr[i]-arr[mid])/x;
        } 
        return mini;
    }
};