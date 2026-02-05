class Solution {
public:
    string reverseByType(string s) {
        int n = s.length();

        int l = 0, r = n-1;
        while(l <= r) {
            if(isalpha(s[l]) && isalpha(s[r])) {
                swap(s[l],s[r]);
                l += 1, r -= 1;
            } else if(!isalpha(s[l]) && !isalpha(s[r])) {
                l += 1, r -= 1;
            } else if(!isalpha(s[l])) {
                l += 1;
            } else {
                r -= 1;
            }
        }

        l = 0, r = n-1;
        while(l <= r) {
            if(!isalpha(s[l]) && !isalpha(s[r])) {
                swap(s[l],s[r]);
                l += 1, r -= 1;
            } else if(isalpha(s[l]) && isalpha(s[r])) {
                l += 1, r -= 1;
            } else if(isalpha(s[l])) {
                l += 1;
            } else {
                r -= 1;
            }
        }
        return s;
    }
};