class Solution {
private:
    int ans = 0;
    void subsets(vector<int> &nums,int i,int xorr) {

        if(i >= nums.size()) return ;

        // pick
        int temp = xorr^nums[i];
        subsets(nums,i+1,temp);
        ans += temp;

        // not-pick
        subsets(nums,i+1,xorr);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        // for "n" elements there are 2^n subsets
        int n = nums.size();
        int xorr = 0; // empty subset
        subsets(nums,0,xorr);
        return ans;
    }
};