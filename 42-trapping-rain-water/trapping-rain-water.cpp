class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1) return 0;

        vector<int> leftMax(n,0), rightMax(n,0);

        for(int i = 1 ; i < n ; i++) leftMax[i] = max(leftMax[i - 1],height[i - 1]);
        for(int i = n - 2 ; i >= 0 ; i--) rightMax[i] = max(rightMax[i + 1],height[i + 1]);

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            int left = leftMax[i], right = rightMax[i];
            int mini = min(left,right);
            int waterLevel = mini - height[i];
            if(waterLevel >= 0) 
                ans += waterLevel;
        }
        return ans;
    }
};