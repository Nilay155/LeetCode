class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> data;
        int n = path.length(), i = 0;

        while(i < n) {
            string curr;
            // handling '///' patterns
            while(i < n && path[i] == '/') {
                curr += path[i];
                i += 1;
            }
            if(!curr.empty())
                data.push_back("/");
            
            curr = "";
            // handling '...' dots but edge case to be handled
            bool alpha = false;
            while(i < n && path[i] != '/') {
                if(isalpha(path[i]))
                    alpha = true;
                curr += path[i];
                i += 1;
            }
            if(!curr.empty()) {
                if(alpha) {
                    data.push_back(curr);
                } else {
                    if(curr.length() <= 2) {
                        if(curr.length() == 1)
                            data.pop_back();
                        else {
                            data.pop_back();
                            if(!data.empty())
                                data.pop_back();
                            if(!data.empty())
                                data.pop_back();
                        }
                    } else {
                        data.push_back(curr);
                    }
                }
            }
        }
        if(data.empty())
            return "/";
        
        if(data.back() == "/" && data.size() > 1) 
            data.pop_back();
        string result;
        for(int i = 0 ; i < data.size() ; i++) {
            result += data[i];
        }
        return result;
    }
};