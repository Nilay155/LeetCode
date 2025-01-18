class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);

        int res = 0;
        int leftOnes = 0;
        for(int i = 0 ; i < n ; i++) {
            res += leftOnes;
            if(boxes[i] == '1') {
                leftOnes += 1;
            }
            ans[i] += res;
        }

        res = 0;
        int rightOnes = 0;
        for(int i = n-1 ; i >= 0 ; i--) {
            res += rightOnes;
            if(boxes[i] == '1') {
                rightOnes += 1;
            }
            ans[i] += res;
        }
        return ans;
    }
};