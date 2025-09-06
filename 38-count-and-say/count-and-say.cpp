class Solution {
private:
    string countSay(int curr,int end,string s) {
        
        string temp;
        int count = 1, element = s[0]-'0', n = s.length();
        for(int i = 1 ; i < n ; i++) {
            if(s[i] == s[i-1]) {
                count += 1;
            } else {
                temp += to_string(count);
                temp += to_string(element);

                count = 1, element = s[i]-'0';
            }
        }
        
        temp += to_string(count);
        temp += to_string(element);
   
        if(curr == end) return temp;
        return countSay(curr + 1,end,temp);
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        return countSay(2,n,"1");
    }
};