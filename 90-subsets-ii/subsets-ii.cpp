class Solution {
private:
    set<vector<int>> st;
    vector<vector<int>> ans;
    vector<int> arr;

    void f(vector<int> &nums,int i,int n) {
        if(i >= n) {
            st.insert(arr);
            return ;
        }

        f(nums,i + 1,n);

        arr.push_back(nums[i]);
        f(nums,i + 1,n);
        arr.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        f(nums,0,n);
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};