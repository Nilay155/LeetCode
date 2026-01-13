class Solution {
public:
    int splitNum(int num) {
        string str = to_string(num);
        sort(str.begin(),str.end());
        bool flag = false;
        int n1 = 0, n2 = 0;
        for(int i = 0 ; i < str.length() ; i++) {
            if(!flag) {
                n1 = n1 * 10 + (str[i] - '0');
            } else {
                n2 = n2 * 10 + (str[i] - '0');
            }
            flag = !flag;
        }
        return n1 + n2;
    }
};