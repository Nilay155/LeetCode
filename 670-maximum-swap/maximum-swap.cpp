class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        int maxi = -1, index = -1,ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--) {
            if(s[i] - '0' > maxi) {
                maxi = s[i] - '0';
                index = i;
            }
            swap(s[i],s[index]);
            ans = max(ans,stoi(s));
            swap(s[i],s[index]);
        }
        return ans;
    }
};