class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.length();
        
        for(int l = 1 ; l <= n ; l++) {
            if(n%l == 0) {
                string cmp = s.substr(0,l);
                vector<int> c1(26,0);
                for(int i = 0 ; i < l ; i++) c1[cmp[i]-'a']++;

                bool flag = true;
                for(int i = l ; i < n ; i += l) {
                    string str = s.substr(i,l);
                    vector<int> c2(26,0);
                    for(int j = 0 ; j < l ; j++) c2[str[j]-'a']++;
                    if(c1 != c2) {
                        flag = false;
                        break;
                    }
                }
                if(flag) return l;
            }
        }
        return n;
    }
};