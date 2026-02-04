class Solution {
public:
int compress(vector<char>& chars) {
    int n = chars.size();
    char ch;
    int count = 0;
    string res;
    for(int i = 0 ; i < n ; i++) {
        if(count == 0) {
            ch = chars[i];
            count += 1;
        } else {
            
            if(ch == chars[i]) {
                count += 1;
            } else {
                // ch != chars[i]
                res += string(1,ch);
                if(count > 1)
                    res += to_string(count);
                ch = chars[i];
                count = 1;
            }
        }
    }
    res += string(1,ch);
    if(count > 1)
        res += to_string(count);
    
    for(int i = 0 ; i < res.length() ; i++) chars[i] = res[i];
    return res.length();
}
};