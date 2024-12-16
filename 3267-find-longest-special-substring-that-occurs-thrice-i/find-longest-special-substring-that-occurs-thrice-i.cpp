class Solution {
public:
    bool check(vector<int> &arr) {
        int flag = 0;
        for(int i = 0 ; i < 26 ; i++) {
            if(arr[i] > 0 && flag) return false;
            if(arr[i] > 0) flag = 1;
        }
        return true;
    }
    bool isPossible(string &s,int k) {
        vector<int> count(26);
        vector<int> temp(26);

        int i = 0, j = 0;
        int n = s.length();

        while(j < n) {
            temp[s[j]-'a']++;
            if((j-i+1)%k == 0) {
                if(check(temp)) {
                    count[s[j]-'a']++;
                }
                temp[s[i]-'a']--;
                i++;
            }
            j++;
        }

        for(int i = 0 ; i < 26 ; i++) {
            if(count[i] > 2) return true;
        }
        return false;
    }
    int maximumLength(string s) {
        int n = s.length();

        int start = 1;
        int end = n;

        while(start <= end) {
            int mid = (start + end) >> 1;
            if(isPossible(s,mid)) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return (end == 0) ? -1 : end;
    }
};