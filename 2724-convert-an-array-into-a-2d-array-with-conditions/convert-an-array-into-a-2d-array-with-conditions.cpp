class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        vector<int> counts(n+1,0);
        for(int x : nums) counts[x]++;

        vector<vector<int>> ans;      
        bool flag = true;
        while(flag) {
            flag = false;
            vector<int> arr;
            for(int i = 1 ; i <= n ; i++) {
                if(counts[i] > 0) {
                    flag = true;
                    arr.push_back(i);
                    counts[i]--;
                }
            }
            if(!arr.empty()) ans.push_back(arr);
        }
        return ans;
    }
};