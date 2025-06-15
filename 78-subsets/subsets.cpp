class Solution {
private:
    void solve(vector<int> &nums,vector<int> &arr,vector<vector<int>> &ans,int i,int n) {

        if(i >= n) {
            ans.push_back(arr);
            return;
        }

        solve(nums,arr,ans,i+1,n);

        arr.push_back(nums[i]);
        solve(nums,arr,ans,i+1,n);
        arr.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        int n = nums.size();
        solve(nums,arr,ans,0,n);
        return ans;
    }
};