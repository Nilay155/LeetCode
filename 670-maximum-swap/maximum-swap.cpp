class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        for(int i = 0 ; i < n ; i++) {
            int maxi = s[i] - '0', index = i;
            for(int j = n - 1 ; j > i ; j--) {
                if(s[j] - '0' > maxi) {
                    index = j;
                    maxi = s[j] - '0';
                }
            }
            if(index != i) {
                swap(s[i],s[index]);
                return stoi(s);
            }
        }
        return num;
    }
};