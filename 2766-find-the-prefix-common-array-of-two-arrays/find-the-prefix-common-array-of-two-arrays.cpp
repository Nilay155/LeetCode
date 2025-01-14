class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int count = 0;
        vector<int> nums(n+1);
        vector<int> ans;

        for(int i = 0 ; i < n ; i++) {
            int ele1 = A[i], ele2 = B[i];
            nums[ele1]++;
            nums[ele2]++;
            if(nums[ele1] == 2 && ele1 != ele2) count++;
            if(nums[ele2] == 2) count++;
            ans.push_back(count);
        }
        return ans;
    }
};