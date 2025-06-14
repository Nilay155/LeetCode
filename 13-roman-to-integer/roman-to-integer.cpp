class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char,int> mpp = 
        {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            
            if(s[i] == 'I') {
                if(i+1 < n) {
                    if(s[i+1] == 'V') {
                        ans += mpp[s[i+1]]-1;
                        i++;
                    } else if(s[i+1] == 'X') {
                        ans += mpp[s[i+1]]-1;
                        i++;
                    } else {
                        ans += mpp[s[i]];
                    }
                } else {
                    ans += mpp[s[i]];
                }
            }
            else if(s[i] == 'X') {
                if(i+1 < n) {
                    if(s[i+1] == 'L') {
                        ans += mpp[s[i+1]]-10;
                        i++;
                    } else if(s[i+1] == 'C') {
                        ans += mpp[s[i+1]]-10;
                        i++;
                    } else {
                        ans += mpp[s[i]];
                    }
                } else {
                    ans += mpp[s[i]];
                }
            }
            else if(s[i] == 'C') {
                if(i+1 < n) {
                    if(s[i+1] == 'D') {
                        ans += mpp[s[i+1]]-100;
                        i++;
                    } else if(s[i+1] == 'M') {
                        ans += mpp[s[i+1]]-100;
                        i++;
                    } else {
                        ans += mpp[s[i]];
                    }
                } else {
                    ans += mpp[s[i]];
                }
            }
            else {
                ans += mpp[s[i]];
            }
        }
        return ans;
    }
};