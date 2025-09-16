class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.length(), m = p.length();

        string left,right;
        int idx = -1;
        for(int i = 0 ; i < m ; i++) {
            if(p[i] == '*') {
                idx = i;
                break;
            }
        }
        
        int u = idx-1, v = idx+1;
        for(int i = 0 ; i <= u ; i++) left.push_back(p[i]);
        for(int i = v ; i < m ; i++) right.push_back(p[i]);

        int l = -1, r = -1, x = left.length(), y = right.length();

        if(x) {
            for(int i = n-x ; i >= 0 ; i--) {
                if(s.substr(i,x) == left) l = i + x - 1;
            }
        }
        if(y) {
            for(int i = 0 ; i <= n-y ; i++) {
                if(s.substr(i,y) == right) r = i;
            }
        }

        if(l == -1 && r == -1 && x == 0 && y == 0) return true;
        else if(l == -1 && x == 0 && r != -1 && y != 0) return true;
        else if(r == -1 &&  y== 0 && l != -1 && x != 0) return true;
        else if(l != -1 && r != -1 && l < r) return true;
        else return false;
    }
};