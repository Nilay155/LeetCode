class Solution {
private:
    vector<vector<int>> ans;
    vector<int> arr;

    void f(int i,vector<int> &freq,vector<int> &nums) {
        if(i >= nums.size()) {
            ans.push_back(arr);
            return ;
        }

        for(int c = 0 ; c <= freq[nums[i] + 10] ; c++) {
            
            if(c > 0) {
                arr.push_back(nums[i]);
                f(i + 1,freq,nums);
            } else {
                f(i + 1,freq,nums);
            }
        }
        while(!arr.empty() && arr.back() == nums[i]) 
            arr.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> freq(21,0);
        for(int f : nums) freq[f + 10] += 1;
        nums.clear();
        for(int i = 0 ; i <= 20 ; i++) {
            if(freq[i])
                nums.push_back(i - 10);
        }
        f(0,freq,nums);
        sort(ans.begin(),ans.end());
        return ans;
    }
};