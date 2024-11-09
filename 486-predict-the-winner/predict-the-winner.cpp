class Solution {
public:
    int solve(vector<int> &nums,int left,int right,int turn) {
        if(left >= right) return (turn == 0) ? -nums[left] : nums[left];

        int score = 0;
        if(turn) {
            score = max(nums[left] + solve(nums,left+1,right,0),
                        nums[right] + solve(nums,left,right-1,0));
        } else {
            score = min(-nums[left] + solve(nums,left+1,right,1),
                        -nums[right] + solve(nums,left,right-1,1));
        }
        // cout << score << endl;
        return score;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // cout << solve(nums,0,n-1,1) << endl;
        return (solve(nums,0,n-1,1) >= 0);
    }
};