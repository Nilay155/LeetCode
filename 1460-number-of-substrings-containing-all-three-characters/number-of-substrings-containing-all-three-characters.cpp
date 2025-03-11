class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int res = 0;

        int a = -1;
        int b = -1;
        int c = -1;
        bool flag = true;

        int j = 0;
        
        while(j < n) {

            if(s[j] == 'a') {
                a = max(a,j);
            }
            else if(s[j] == 'b') {
                b = max(b,j);
            }
            else {
                c = max(c,j);
            }
            if(a != -1 && b != -1 && c != -1) {
                int k = min({a,b,c});
                res += k+1;
            }
            j++;
        }
        return res;
    }
};