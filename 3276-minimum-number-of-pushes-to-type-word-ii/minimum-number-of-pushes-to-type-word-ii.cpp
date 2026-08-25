class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> counts(26,0);
        for(char ch : word) 
            counts[ch - 'a'] += 1;
        
        vector<pair<int,int>> frequencies;
        for(int i = 0 ; i < 26 ; i++) {
            if(counts[i] > 0)
                frequencies.push_back({counts[i],i});
        }

        sort(frequencies.begin(),frequencies.end(),[&](pair<int,int> &A,pair<int,int> &B) {
            return A.first > B.first;
        });

        int count = 0, ans = 0, m = frequencies.size();

        for(int i = 0 ; i < m ; i++) {
            auto [cnt,k] = frequencies[i];
            int temp = (count + 8) / 8;
            ans += temp * cnt;
            count += 1;
        }
        return ans;
    }
};