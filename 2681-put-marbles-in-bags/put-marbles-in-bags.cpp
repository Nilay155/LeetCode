// Recursive Solution
// [1,3,5,1]
// (i,k,j)=> O(n^2 * k)

// Optimal Solution
// [1,3,5,1]

// pair weights => [4,8,6] => [4,6,8]
class Solution {
private:
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        vector<int> nums;
        for(int i = 0 ; i < n-1 ; i++) {
            nums.push_back(weights[i] + weights[i+1]);
        }
        long long maxi = 0;
        long long mini = 0;
        
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < k-1 ; i++) {
            mini += nums[i];
            maxi += nums[n-i-2];
        }
        return maxi-mini;
    }
};