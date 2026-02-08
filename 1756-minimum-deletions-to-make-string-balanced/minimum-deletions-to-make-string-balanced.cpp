class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        int a = 0, b = 0;
        for(char ch : s) {
            if(ch == 'a') a += 1;
            else b += 1;
        }
        int l = 0, r = n-1;
        // while(r >= 0 && s[r] == 'b') r -= 1;
        // while(l < n && s[l] == 'a') l += 1;

        int ans = 1e5,c = 0, x = 0;
        char ch;

        for(int i = r ; i >= l ; i--) {
            if(c == 0) {
                c = 1;
                ch = s[i];
            } else {

                if(ch == s[i]) c += 1;
                else {
                    if(ch == 'a') {
                        int op1 = b;
                        int op2 = c;
                        ans = min(ans,x + op1);
                        x += op2;
                    } else {
                        b -= c;
                    }
                    c = 1, ch = s[i];
                }
                
            }
        }
        if(ch == 'a') {
            int op1 = b;
            int op2 = c;
            ans = min(ans,x + op1);
            x += op2;
        }
        ans = min(ans,x);
        return ans == 1e5 ? 0 : ans;
    }
};