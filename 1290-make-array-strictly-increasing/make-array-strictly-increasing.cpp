class Solution {
private:
    int dp[2000][2000][2];
    int f(vector<int> &arr1,vector<int> &arr2,int i,int prev,int flag) {
        if(i >= arr1.size())
            return 0; // means the array has reached a sorted state 
        if(dp[i][prev][flag] != -1)
            return dp[i][prev][flag];
        
        int lastElement;
        if(flag) {
            lastElement = arr1[prev];
        } else {
            lastElement = arr2[prev];
        }

        int op1 = 1e9;
        if(arr1[i] > lastElement) {
            op1 = 0 + f(arr1,arr2,i + 1,i,1);
        }

        int op2 = 1e9;
        int j = upper_bound(arr2.begin(), arr2.end(), lastElement) 
                - arr2.begin();

        if (j < arr2.size()) {
            op2 = min(op2, 1 + f(arr1, arr2, i + 1, j, 0));
        }
        return dp[i][prev][flag] = min(op1,op2);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());

        memset(dp,-1,sizeof(dp));
        int k1 = f(arr1,arr2,1,0,1);
        int m = (int)arr2.size();
        
        arr1[0] = arr2[0];
        memset(dp,-1,sizeof(dp));
        int k2 = 1 + f(arr1,arr2,1,0,1);
        // cout << k1 << " : " << k2 << "\n";
        return min(k1,k2) >= 1e9 ? -1 : min(k1,k2);
    }
};