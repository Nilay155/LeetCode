class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();

        int t = 0, f = 0;
        int l = 0, r = 0, ans = 0;

        while(r < n) {
            if(answerKey[r] == 'T')
                t += 1;
            else
                f += 1;
            
            int mini = min(t,f);
            if(mini <= k)
                ans = max(ans,r - l + 1);
            else {
                while(l < r && mini > k) {
                    if(answerKey[l] == 'T')
                        t -= 1;
                    else
                        f -= 1;
                    mini = min(t,f);
                    l += 1;
                }
            }
            r += 1;
        }
        return ans;
    }
};