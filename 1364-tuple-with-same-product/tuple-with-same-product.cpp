class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // a*b == c*d -> tuple (a,b,c,d)
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                int product = nums[i]*nums[j];
                mpp[product]++;
            }
        } 

        int ans = 0;
        for(auto& it : mpp) {
            // it.first && it.second
            // cout << it.first << "  " << it.second << endl;
            if(it.second == 2) ans += 8;
            else if(it.second > 2) {
                ans += (it.second)*(it.second-1)*2*2;
            }
        }  
        return ans;
    }
};