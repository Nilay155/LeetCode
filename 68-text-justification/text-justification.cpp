class Solution {
private:
    void lastLine(vector<string> &arr,vector<string> &ans,int chars,int spaces,int maxWidth) {
        int spacesLeft = maxWidth - chars;
        int words = arr.size();

        string res;
        for(int i = 0 ; i < words ; i++) {
            res += arr[i];
            if(i == words-1) {
                res.append(spacesLeft,' ');
                break;
            }
            if(spacesLeft) {
                res.append(1,' ');
                spacesLeft -= 1;
            }
        }
        ans.push_back(res);
    }
    void addContent(vector<string> &arr,vector<string> &ans,int chars,int spaces,int maxWidth) {
        int spacesLeft = maxWidth - chars;
        int words = arr.size();

        int gap = spacesLeft/((words-1) == 0 ? 1 : words-1);
        int extraGaps = spacesLeft%((words-1) == 0 ? 1 : words-1);
        cout << extraGaps << endl;
        string res;
        for(int i = 0 ; i < words ; i++) {
            res += arr[i];
            if(i == words-1) {
                int diff = maxWidth - res.size();
                if(diff > 0) res.append(diff,' ');
                break;
            }
            res.append(gap,' ');
            if(extraGaps) {
                res.append(1,' ');
                extraGaps -= 1;
            }
        }
        ans.push_back(res);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;

        int i = 0;
        while(i < n) {
            int chars = 0;
            int spaces = 0;
            int len = words[i].size();
            vector<string> temp;

            while(i < n && chars + spaces +  len <= maxWidth) {
                chars += len;
                temp.push_back(words[i]);
                spaces += 1;
                i++;
                if(i < n) len = words[i].size();
            }
            
            // If it's a line
            if(i >= n)
                lastLine(temp,ans,chars,spaces,maxWidth); 
            // or if it's not
            else 
                addContent(temp,ans,chars,spaces,maxWidth);
        }
        return ans;
    }
};