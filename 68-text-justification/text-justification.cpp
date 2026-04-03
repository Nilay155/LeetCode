class Solution {
private:
    void fullJustify(int i,int count,int totalLength,vector<string> &ans,int maxWidth,vector<string>& words) {
        int j = i - count;  
        int spaces = maxWidth - totalLength;

        if(count == 1) {
            string res = words[j];
            res.append(spaces,' ');
            ans.push_back(res);
            return ;
        }
        int q = spaces / (count - 1);
        int k = q;
        int r = spaces % (count - 1);

        string res;
        while(j < i) {
            res += words[j];
            if(count > 1) {
                res.append(k,' ');
                count--;
            }
            if(r > 0) {
                res.append(1,' ');
                r--;
            }
            j += 1;
        }
        ans.push_back(res);
    }
    void leftJustify(int i,int count,int totalLength,vector<string> &ans,int maxWidth,vector<string>& words) {
        int j = i - count;
        int spaces = maxWidth - totalLength;

        if(count == 1) {
            string res = words[j];
            res.append(spaces,' ');
            ans.push_back(res);
            return;
        }
        string res;
        while(j < i) {
            res += words[j];
            if(spaces > 0) {
                spaces--;
                res.append(1,' ');
            }
            j += 1;
        }
        if(spaces > 0)
            res.append(spaces,' ');
        ans.push_back(res);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n = words.size();
        vector<string> ans;

        int i = 0, count = 0, totalLength = 0;
        while(i < n) {
            if(totalLength + count + words[i].length() > maxWidth) {
                // for the last count words do the simulation
                fullJustify(i,count,totalLength,ans,maxWidth,words);
                totalLength = 0;
                count = 0;
            } else {
                totalLength += words[i].length();
                count += 1;
                i += 1;
            }
        }

        if(count > 0)
            leftJustify(i,count,totalLength,ans,maxWidth,words);
        return ans;
    }
};