class Solution {
public:
    bool checkValidCuts(int m, vector<vector<int>>& rectangles) {
        int n = rectangles.size();

        sort(rectangles.begin(),rectangles.end(),[&](vector<int> &A,vector<int> &B) {
            
            if(A[1] == B[1]) 
                return A[3] < B[3];
            return A[1] < B[1];
        });

        int countY = 0, countX = 0;

        int sy = rectangles[0][1], ey = rectangles[0][3];
        for(int i = 1 ; i < n ; i++) {

            int nsy = rectangles[i][1], ney = rectangles[i][3];

            if(nsy >= ey) {
                countY += 1;
            }
            sy = nsy, ey = max(ney,ey);
        }

        sort(rectangles.begin(),rectangles.end(),[&] (vector<int> &A,vector<int> &B) {

            if(A[0] == B[0])
                return A[2] < B[2];
            return A[0] < B[0];
        });

        int sx = rectangles[0][0], ex = rectangles[0][2];
        for(int i = 1 ; i < n ; i++) {
            int nsx = rectangles[i][0], nex = rectangles[i][2];
            if(nsx >= ex) {
                countX += 1;
            } 
            sx = nsx, ex = max(ex,nex);
        }
        return (countX >= 2 || countY >= 2);
    }
};