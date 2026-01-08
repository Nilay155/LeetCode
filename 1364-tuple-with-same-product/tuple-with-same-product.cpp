class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> products;

        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                products[nums[i] * nums[j]] += 1;
            }
        }

        int ans = 0;
        for(auto [product,count] : products) {
            ans += 4 * (count - 1) * (count);
        }
        return ans;
    }
};