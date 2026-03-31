class Solution {
private:
    string binaryAddition(string &s) {
        string str;
        int c = 1, n = s.length();
        for(int i = n - 1 ; i >= 0 ; i--) {

            if(s[i] == '1' && c) {
                str.push_back('0');
                c = 1;
            } else if(s[i] == '0' && c){
                str.push_back('1');
                c = 0;
            } else {
                // c == 0 for sure
                str.push_back(s[i]);
            }
        }
        if(c) str.push_back('1');
        reverse(str.begin(),str.end());
        return str;
    }
public:
    int numSteps(string s) {
        int steps = 0, n = s.length();
        int carry = 0;
        for(int i = n - 1 ; i >= 1 ; i--) {
            int total = (s[i] - '0') + carry;
            if(total == 1) {
                carry = 1;
                steps += 2;
            } else {
                if(total == 2) carry = 1;
                steps += 1;
            }
        }
        if(carry) steps += 1;
        return steps;
    }
};