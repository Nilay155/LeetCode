class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();

        unordered_map<char,int> mpp;
        for(char ch : tasks) mpp[ch]++;

        int maxi = 0;
        for(auto [ch,count] : mpp) maxi = max(maxi,count);

        int cnt = 0;
        for(auto [ch,count] : mpp) if(count == maxi) cnt += 1;

        int cycles = maxi - 1;
        int wait = cycles * k;
        int minimumTime = wait + maxi + cnt - 1;
        return minimumTime < n ? n : minimumTime;
    }
};