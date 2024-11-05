class Solution {
public:
    int minChanges(string s) {
        int n = s.size();

        int res = 0;
 
        for(int i = 0 ; i < n-1 ; i += 2) {
            if(s[i] != s[i+1]) res += 1;
        }
        return res;
    }
};