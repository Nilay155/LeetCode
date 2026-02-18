class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();

        vector<int> counts(26,0);
        for(char ch : tasks) counts[ch-'A'] += 1;
        
        unordered_map<int,int> freq;
        int maxFreq = 0;
        for(int count : counts) if(count) freq[count] += 1, maxFreq = max(maxFreq,count);

        int k1 = (maxFreq-1) * (n + 1) + freq[maxFreq];
        if(k1 < m) k1 = m;
        return k1;
    }
};