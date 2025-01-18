class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        int m = shifts.size();
        
        vector<int> arr(n);
        for(int i = 0 ; i < m ; i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if(direction) {
                arr[start] += 1;
                if(end+1 < n) arr[end+1] -= 1;
            } else {
                arr[start] -= 1;
                if(end+1 < n) arr[end+1] += 1;
            }
        }

        for(int i = 1 ; i < n ; i++) arr[i] = arr[i] + arr[i-1];

        string ans;
        for(int i = 0 ; i < n ; i++) {
            int temp = ((arr[i] + (s[i]-'a') + 26)%26 + 26)%26;
            char ch = (temp + 'a');
            ans.push_back(ch);
        }
        return ans;
    }
};