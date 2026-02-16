class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        
        int l = 0, r = 0,count = 0;
        unordered_map<int,int> S,T;
        for(char ch : s1) S[ch] += 1;
        int k = S.size();
        // cout << S.size() << "\n";
        while(r < m) {
            T[s2[r]] += 1;
            
            if(T[s2[r]] == S[s2[r]]) count += 1;

            while(l <= r && S[s2[r]] < T[s2[r]]) {
                if(T[s2[l]] == S[s2[l]]) count -= 1;
                T[s2[l]] -= 1;
                l += 1;
            }
            if(count == k) return true;
            r += 1;
        } 
        return false;
    }
};