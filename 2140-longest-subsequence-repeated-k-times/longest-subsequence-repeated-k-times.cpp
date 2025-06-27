class Solution {
private:
    bool check(string s,string curr,int k) {
        int n = s.length();
        int m = curr.length();

        int j = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == curr[j]) {
                j += 1;
                if(j == m) {
                    j = 0;
                    count += 1;
                }
            }
        }
        return count >= k;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        
        queue<string> q;
        q.push("");
        string ans;
        while(!q.empty()) {
            string front = q.front(); q.pop();

            for(char ch = 'a' ; ch <= 'z' ; ch++) {
                string next = front + ch;
                if(check(s,next,k)) {
                    q.push(next);
                }
            }
            ans = front;
        }
        return ans;
    }
};