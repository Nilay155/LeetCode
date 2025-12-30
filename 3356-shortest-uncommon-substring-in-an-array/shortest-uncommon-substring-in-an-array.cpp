class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        int n = arr.size();
        // PreComputing Count of all substrings
        unordered_map<string,int> count;
        for(int i = 0 ; i < n ; i++) {
            string s = arr[i];
            int m = s.length();
            for(int j = 0 ; j < m ; j++) {
                for(int k = j ; k < m ; k++) {
                    count[s.substr(j,k-j+1)] += 1;
                }
            }
        }

        // Creating answer array
        vector<string> ans;

        // Finding if any substrings match or not
        for(int i = 0 ; i < n ; i++) {
            
            string s = arr[i];
            int m = s.length();
            
            unordered_map<string,int> mpp;
            for(int j = 0 ; j < m ; j++) {
                for(int k = j ; k < m ; k++) {
                    mpp[s.substr(j,k-j+1)] += 1;
                }
            }

            // Computing the answer
            string res = "";
            for(int j = 0 ; j < m ; j++) {
                for(int k = j ; k < m ; k++) {
                    string str = s.substr(j,k-j+1);
                    if(count[str]-mpp[str] <= 0) {
                        // A potential Answer Found
                        if(res.length() == 0) res = str;
                        else if(str.length() < res.length()) res = str;
                        else if(str.length() == res.length() && str < res) res = str;
                    }
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};