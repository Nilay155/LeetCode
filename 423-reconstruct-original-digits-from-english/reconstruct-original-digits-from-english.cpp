class Solution {
private:
    unordered_map<int,string> integerString;
    unordered_map<int,char> firstChar;
    void mapping() {
        integerString[0] = "zero",firstChar[0] = 'z';
        integerString[1] = "one",firstChar[1] = 'o';
        integerString[2] = "two",firstChar[2] = 'w';
        integerString[3] = "three",firstChar[3] = 't';
        integerString[4] = "four",firstChar[4] = 'u';
        integerString[5] = "five",firstChar[5] = 'f';
        integerString[6] = "six",firstChar[6] = 'x';
        integerString[7] = "seven",firstChar[7] = 's';
        integerString[8] = "eight",firstChar[8] = 'g';
        integerString[9] = "nine",firstChar[9] = 'i';
        return ;
    }
    char uniqueChar(unordered_map<char,int> &charCounts,int ch) {
        char c = firstChar[ch];
        if(charCounts[c] > 0)
            return c;
        return '*';
    }
public:
    string originalDigits(string s) {
        int n = s.length();
        mapping();
        unordered_map<char,int> charCounts;
        charCounts['*'] = 0;
        for(char ch : s) charCounts[ch] += 1;

        string ans;
        // first unique guaranteed
        for(int k = 0 ; k <= 8 ; k += 2) {
            int count = charCounts[uniqueChar(charCounts,k)];
            if(count > 0) {
                ans.append(count,'0' + k);
                string str = integerString[k];
                for(int i = 0 ; i < str.length() ; i++) {
                    charCounts[str[i]] -= count;
                }
            }
        }
        // second unique
        for(int k = 1 ; k <= 9 ; k += 2) {
            int count = charCounts[uniqueChar(charCounts,k)];
            if(count > 0) {
                ans.append(count,'0' + k);
                string str = integerString[k];
                for(int i = 0 ; i < str.length() ; i++) {
                    charCounts[str[i]] -= count;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};