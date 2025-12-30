class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();

        int k = n;
        for(int i = 0 ; i < n ; i++) k = max(k,int(nums[i].size()));
        int count = 2*k - 1; // diagonals

        vector<vector<int>> adjList(count);

        for(int i = n-1 ; i >= 0 ;i--) {
            int m = nums[i].size();
            for(int j = m-1 ; j >= 0 ; j--) {
                adjList[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < count ; i++) {
            for(int j = 0 ; j < adjList[i].size() ; j++) {
                ans.push_back(adjList[i][j]);
            }
        }
        return ans;
    }
};