class Solution {
public:
    int appendCharacters(string source, string target) {
    int n = source.length(),m = target.length();
    int i = 0, j = 0;
    
    while(i < n && j < m) {
        if(source[i] == target[j]) {
            i += 1,j += 1;
        } else {
            i += 1;
        }
    }
    return m - j;
    }
};