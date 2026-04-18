class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        unordered_map<string,bool> mapper;
        for(auto str : wordList) mapper[str] = true;
        
        queue<string> q;
        unordered_map<string,bool> vis;
        vis[beginWord] = true;
        q.push(beginWord);

        int count = 1;
        while(!q.empty()) {
            int sz = q.size();
            for(int k = 0 ; k < sz ; k++) {
                string str = q.front(); q.pop();
                if(str == endWord)
                    return count;
                for(int l = 0 ; l < str.length() ; l++) {
                    for(char ch = 'a'; ch <= 'z' ; ch++) {
                        string nextStr = str;
                        nextStr[l] = ch;
                        if(mapper.find(nextStr) != mapper.end() && !vis[nextStr]) {
                            vis[nextStr] = true;
                            q.push(nextStr);
                        }
                    }
                }
            
            }
            count += 1;
        }
        return 0;
    }
};