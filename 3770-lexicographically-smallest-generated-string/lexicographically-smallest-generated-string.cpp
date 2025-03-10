class Solution {
public:
    Solution() {
 std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
}
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        string ans(n + m - 1, ' ');  
        vector<int> blocked(n + m - 1, 0);

        for(int i = 0 ; i < n ; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    ans[i + j] = str2[j];  
                    blocked[i + j] = 1;  
                }
            }
        }

        // Validate 'T' conditions
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T' && ans.substr(i, m) != str2) return "";
            if(str1[i] == 'F' && ans.substr(i, m) == str2) return "";
        }

        // Filling 'F' positions
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                for(int k = m-1 ; k >= 0 ; k--) {
                    if(!blocked[i+k]) {
                        for(char ch = 'a'; ch <= 'z'; ch++) {
                            ans[i+k] = ch;
                            if(ans.substr(i,m) != str2) break;
                            else {
                                cout << i << endl;
                                blocked[i+k] = 1;
                                ans[i+k] = ch + 1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};