class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int> pq;
        for(int f : nums) pq.push(f);

        long long ans = 0;
        while(k--) {
            int top = pq.top(); pq.pop();
            int newScore = ceil((double)top / 3.00);
            // cout << top << "  " << newScore << "\n";
            pq.push(newScore);
            ans += top;
        }
        return ans;
    }
};