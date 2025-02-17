class Solution {
private:
    string solve(stack<string> &st) {

        vector<string> ans;

        while(!st.empty()) {
            string str = st.top(); st.pop();
            if(str == "/" || str == ".") continue;
            if(str == "..") {
                // Logic To Handle
                int count = 0;
                while(!st.empty() && (st.top() == ". " || st.top() == "..")) {
                    if(st.top() == "..") count += 1;
                    st.pop();
                    
                }
                if(!st.empty()) st.pop();
                while(count--) st.push("..");
                
            } else {
                ans.push_back(str);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size() == 0) return "/";
        string res;
        for(int i = 0 ; i < ans.size(); i++) {
            res += "/";
            res += ans[i];
        }
        return res;
    }
public:
    string simplifyPath(string path) {
        int n = path.size();
        int i = 0;
        stack<string> st;

        while(i < n) {
            string temp;
            while(i < n && path[i] == '/') {
                i++;
            }
            while(i < n && path[i] == '.') {
                temp += path[i];
                i++;
            }
            if(i < n && path[i] == '/') {
                if(temp.size() >= 2) st.push(temp);
                temp.clear();
            }

            while(i < n && path[i] != '/' ) {
                temp += path[i];
                i++;
            }
            if(temp.size()) st.push(temp);
            temp.clear();

        }
        // while(!st.empty()) {
        //     cout << st.top() << "  " ;
        //     st.pop();
        // }
        return solve(st);
        // return "";
    }
};