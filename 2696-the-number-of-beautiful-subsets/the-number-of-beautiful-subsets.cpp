class Solution {
private:
    int f(vector<int> &nums,vector<int> &subset,int i,int &n,int &k) {
        if(i >= n) {
            int m = subset.size();
            bool flag = true;
            for(int u = 0 ; u < m ; u++)
                for(int v = u + 1; v < m ; v++)
                    if(abs(subset[u] - subset[v]) == k) {
                        flag = false;
                        break;
                    }
            if(!flag || m == 0)
                return 0;
            return 1;
        }

        int notPick = f(nums,subset,i + 1,n,k);
        
        subset.push_back(nums[i]);
        int pick = f(nums,subset,i + 1,n,k);
        subset.pop_back();

        return pick + notPick;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> arr;
        int n = nums.size();
        return f(nums,arr,0,n,k);
    }
};