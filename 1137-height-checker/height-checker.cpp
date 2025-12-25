class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr = heights;
        sort(arr.begin(),arr.end());
        int count = 0, n = arr.size();
        for(int i = 0 ; i < n ; i++) {
            if(heights[i] != arr[i]) count += 1;
        }
        return count;
    }
};