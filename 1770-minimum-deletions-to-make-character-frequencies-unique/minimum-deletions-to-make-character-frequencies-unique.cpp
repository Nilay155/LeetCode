class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();

        vector<int> count(26,0);
        for(char ch : s) count[ch - 'a'] += 1;

        vector<int> frequencies;
        for(int i = 0 ; i < 26 ; i++) 
            if(count[i] > 0)
                frequencies.push_back(count[i]);
        
        sort(frequencies.begin(),frequencies.end());

        int m = frequencies.size(), deletions = 0;
        int limit = frequencies[m - 1];
        for(int i = m - 2 ; i >= 0 ; i--) {
            int freq = frequencies[i];
            if(freq >= limit) {
                int extra = freq - limit + 1;
                deletions += extra;
                limit -= 1;
                if(limit <= 0) limit = 1;
            } else {
                limit = freq;
            }
        }
        return deletions;
    }
};