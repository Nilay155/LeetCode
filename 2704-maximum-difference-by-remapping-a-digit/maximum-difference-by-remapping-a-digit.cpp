class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxi = s, mini = s;
        int n = s.length();
        char map = 'a';

        for(int i = 0 ; i < n ; i++) {
            if(maxi[i] != '9') {
                if(map == 'a') {
                    map = maxi[i];
                    maxi[i] =  '9';
                } else {
                    if(maxi[i] == map) maxi[i] = '9';
                }
            }
        }
        map = 'a';
        for(int i = 0 ; i < n ; i++) {
            if(mini[i] != '0') {
                if(map == 'a') {
                    map = mini[i];
                    mini[i] = '0';
                } else {
                    if(mini[i] == map) mini[i] = '0';
                }
            }
        }
        // cout << maxi << "  " << mini;
        return stoi(maxi) - stoi(mini);
    }
};