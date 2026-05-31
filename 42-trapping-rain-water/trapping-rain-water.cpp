class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;

        int s = 1, e = n - 2, leftMax = height[0], rightMax = height[n - 1];
        int ans = 0;
        while(s <= e) {
            
            if(rightMax < leftMax) {
                int mini = min(leftMax,rightMax);
                int waterLevel = mini - height[e];
                if(waterLevel > 0) ans += waterLevel; 
                rightMax = max(rightMax,height[e]);
                e--;   
            } else {
                int mini = min(leftMax,rightMax);
                int waterLevel = mini - height[s];
                if(waterLevel > 0) ans += waterLevel;
                leftMax = max(leftMax,height[s]);
                s++;  
            }
        }
        return ans;
    }
};