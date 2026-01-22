class Solution {
private:
    int f(vector<int> &nums,int l,int r,int moves) {
        if(r - l + 1 <= 1) return 0;
        if(moves == 0) return nums[r] - nums[l];

        int op1 = f(nums,l+1,r,moves - 1);
        int op2 = f(nums,l,r-1,moves - 1);
        return min(op1,op2);
    }
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return f(nums,0,n-1,3);
    }
};