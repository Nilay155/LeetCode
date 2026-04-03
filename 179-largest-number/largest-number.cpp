class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int num : nums) arr.push_back(to_string(num));
        sort(arr.begin(),arr.end(),[&] (string &A,string &B){
            return A + B > B + A;
        });

        string ans;
        for(string s : arr) ans += s;
        int m = ans.length();
        // int m = 10;
        for(int i = 0 ; i < m ; i++) {
            if(ans[i] != '0')
                return ans.substr(i,m - i);
        }
        return "0";
    }
};