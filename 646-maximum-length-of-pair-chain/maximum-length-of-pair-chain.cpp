class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),[&](vector<int> &A,vector<int> &B) {
            if(A[1] == B[1]) 
                return A[0] < B[0];
            return A[1] < B[1];
        });

        int end = pairs[0][1];
        int count = 1;

        for(int i = 1 ; i < n ; i++) {
            int newStart = pairs[i][0], newEnd = pairs[i][1];

            if(newStart > end) {
                count += 1;
                end = newEnd;
            }
        }
        return count;
    }
};