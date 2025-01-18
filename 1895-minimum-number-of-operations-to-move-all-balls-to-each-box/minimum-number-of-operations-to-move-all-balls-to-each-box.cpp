class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ones;

        for(int i = 0 ; i < n ; i++) {
            if(boxes[i] == '1') ones.push_back(i);
        }

        vector<int> ans;
        int m = ones.size();
        for(int i = 0 ; i < n ; i++) {
            
            int res = 0;
            for(int j = 0 ; j < m ; j++) {
                if(i == ones[j]) continue;
                res += abs(i-ones[j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};