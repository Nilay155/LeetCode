class Solution {
private:
    void mergeIntervals(vector<vector<int>> &intervals,int &n) {
        int end = intervals[0][1];
        vector<vector<int>> temp;
        for(int i = 1; i < n ; i++) {
            int start = intervals[i][0];
        }
    }
public:
    bool checkValidCuts(int m, vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<vector<int>> vertical,horizontal;
        // veritical -> (x-axis)
        // horizontal -> (y-axis)

        for(auto rectangle : rectangles) {
            vertical.push_back({rectangle[0],rectangle[2]});
            horizontal.push_back({rectangle[1],rectangle[3]});
        }
        sort(vertical.begin(),vertical.end());
        sort(horizontal.begin(),horizontal.end());

        int cnt = 1;
        int end = vertical[0][1];
        for(int i = 1 ; i < n ; i++) {
            int start = vertical[i][0];

            if(end <= start) {
                cnt += 1;
            } 
            //else {
            //     if(vertical[i][1] > end)
            //         cnt = 1;
            // }
            end = max(end,vertical[i][1]);
        }
        if(cnt >= 3) return true;

        cnt = 1;
        end = horizontal[0][1];
        // cout << horizontal[0][0] << " : " << horizontal[0][1] << " : " << cnt << endl;
        for(int i = 1 ; i < n ; i++) {
            int start = horizontal[i][0];

            if(end <= start) {
                cnt += 1;
            }
            // else {
            //     // Collision - merge

            // }
            // cout << horizontal[i][0] << " : " << horizontal[i][1] << " : " << cnt << endl;
            end = max(end,horizontal[i][1]);
        }
        return cnt >= 3;
    }
};