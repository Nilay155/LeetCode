class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int j = n - 1;

        int lastWordLength = 0;

        while(j >= 0 && s[j] == ' ') j--;
        while(j >= 0 && s[j] != ' ') j--,lastWordLength += 1;
        return lastWordLength; 
    }
};