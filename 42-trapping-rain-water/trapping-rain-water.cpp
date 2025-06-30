class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i = 1 ; i < n ; i++) {
            leftMax[i] = max(height[i],leftMax[i-1]);
            rightMax[n-i-1] = max(height[n-i-1],rightMax[n-i]);
        }

        int ans = 0;
        for(int i = 1 ; i < n-1 ; i++) {
            int water = min(leftMax[i-1],rightMax[i+1]);
            ans += (water-height[i] >= 0 ? water-height[i] : 0);
        }
        return ans;
    }
};