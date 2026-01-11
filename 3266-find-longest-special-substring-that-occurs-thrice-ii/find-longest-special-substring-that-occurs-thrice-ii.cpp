class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> arr(26);

        char ch;
        int c = 0;
        for(int i = 0 ; i < n ; i++) {
            if(c == 0) {
                c = 1;
                ch = s[i];
            } else if(ch == s[i]) {
                c += 1;
            } else {
                arr[ch - 'a'].push_back(c);
                c = 1;
                ch = s[i];
            }
        }
        arr[ch - 'a'].push_back(c);

        for(int i = 0 ; i < 26 ; i++) {
            sort(arr[i].begin(),arr[i].end());
        }

        int ans = -1;
        for(int i = 0 ; i < 26 ; i++) {
            // make 3 special strings from one sequence
            for(int j = 0 ; j < (int) arr[i].size() ; j++) {
                ans = max(ans,arr[i][j] - 2);
            }
            // three sequences making 3 special strings
            for(int j = 0 ; j < (int) arr[i].size() - 2; j++) {
                ans = max(ans,arr[i][j]);
            }
            // two sequences making 3 special strings
            for(int j = 0 ; j < (int) arr[i].size() - 1 ; j++) {
                if(arr[i][j+1] > arr[i][j]) {
                    ans = max(ans,arr[i][j]);
                } else {
                    ans = max(ans,arr[i][j] - 1);
                }
            }
        } 
        return ans == 0 ? -1 : ans;
    }
};