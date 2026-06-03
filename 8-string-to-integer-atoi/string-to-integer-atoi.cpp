class Solution {
public:
    int myAtoi(string s) {
        
        bool neg = false;
        
        int i = 0, n = s.length();
        long long ans = 0;
        // skipping empty spaces
        while(i < n && s[i] == ' ') i++;
        // checking -ve or +ve number
        if(i < n && s[i] == '-') neg = true, i++;
        else if(i < n && s[i] == '+') neg = false, i++;

        // ignoring leading zeroes
        while(i < n && s[i] == '0') i++;

        // Now computing the acutal result
        long long ub = llabs(neg ? INT_MIN : INT_MAX);
        while(i < n && isdigit(s[i])) {
            if(ans > ub/10) {
                ans = ub;
                break;
            }
            ans = ans * 10 + s[i] - '0';
            if(ans > ub) {
                ans = ub;
                break;
            }
            i++;
        }
        if(neg) return -ans;
        else return ans;

    }
};