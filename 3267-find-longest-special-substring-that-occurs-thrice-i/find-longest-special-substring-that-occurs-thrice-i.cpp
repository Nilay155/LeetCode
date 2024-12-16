class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        unordered_map<string,int> mpp;

        for(int i = 0 ; i < n ; i++) {
            string temp;
            temp.push_back(s[i]);
            mpp[temp]++;
            for(int j = i+1 ; j < n ; j++) {
                if(temp.back() == s[j]) {
                    temp.push_back(s[j]);
                    mpp[temp]++;
                } else {
                    break;
                }

            }
        }

        int ans = -1;

        for(auto& it : mpp) {
            if(it.second >= 3) {
                
                string temp = it.first;
                int len = temp.size();
                // cout << temp << endl;
                ans = max(ans,len);
            }
        }
        return ans;
    }
};