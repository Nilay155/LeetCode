class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> freq;
        for(int f : arr) freq[f] += 1;

        vector<int> frequencies;
        for(auto [e,c] : freq) {
            frequencies.push_back(c);
        }
        sort(frequencies.rbegin(),frequencies.rend());
        int half = n / 2;
        int deleteCount = 0, ans = 0;
        for(int i = 0 ; i < frequencies.size() ; i++) {
            deleteCount += frequencies[i];
            ans += 1;
            if(deleteCount >= half)
                return ans;
        }
        return ans;
    }
};