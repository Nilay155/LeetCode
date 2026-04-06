class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        sort(banned.begin(),banned.end());
        // for(int b : banned) cout << b << "   ";
        int sum = 0, i = 0, count = 0;
        for(int k = 1 ; k <= n  && sum + k <= maxSum; k++) {
            sum += k;
            count += 1;
            if(i < m && banned[i] == k) {
                sum -= k;
                count -= 1;
                while(i < m && banned[i] == k) i++;
            }
        }
        return count;
    }
};