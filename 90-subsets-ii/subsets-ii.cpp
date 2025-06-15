class Solution {
private:
    void solve(vector<vector<int>> &ans,vector<int> &arr,vector<int> &nums,int i,int &n) {
        ans.push_back(arr);
        if(i >= n) {
            return;
        }

        for(int j = i ; j < n ; j++) {
            if(j > i && nums[j] == nums[j-1]) continue;
            
            arr.push_back(nums[j]);
            solve(ans,arr,nums,j+1,n);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        solve(ans,arr,nums,0,n);
        return ans;
    }
};