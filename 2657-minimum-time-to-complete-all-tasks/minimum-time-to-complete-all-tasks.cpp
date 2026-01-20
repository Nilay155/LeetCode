class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<bool> numberLine(2001,false);

        sort(tasks.begin(),tasks.end(),[&](const vector<int> &A,const vector<int> &B) {
            if(A[1] == B[1]) return A[0] > B[0];
            else return A[1] < B[1];
        });

        for(int i = 0 ; i < n ; i++) {

            int count = 0;
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];

            for(int j = end ; j >= start ; j--) {
                if(numberLine[j])
                    count += 1;
            }
            int remaining = duration - count;
            for(int j = end ; j >= start ; j--) {
                if(!numberLine[j] && remaining > 0) {
                    numberLine[j] = true;
                    remaining -= 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= 2000 ; i++) {
            if(numberLine[i])
                ans += 1;
        }
        return ans;
    }
};