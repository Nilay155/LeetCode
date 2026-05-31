class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        int jumps = 0, maxJumps = nums[0] - 1, endIndex = nums[0];
        int nextJump = 0, nextIndex;

        if(maxJumps + 1 >= n - 1) 
            return jumps + 1;
        
        for(int i = 1 ; i < n - 1 ; i++) {
            int currJump = i + maxJumps;
            if(currJump >= n - 1)
                return jumps + 1;
            
            if(nextJump < i + nums[i]) {
                nextJump = i + nums[i];
                nextIndex = i;
            }
            
            if(i == endIndex) {
                maxJumps = nums[nextIndex] - (i - nextIndex) - 1;;
                endIndex = nextJump;
                jumps += 1;
                nextJump = 0;
            } else {
                maxJumps -= 1;
            }
        }
        return jumps + 1;
    }
};