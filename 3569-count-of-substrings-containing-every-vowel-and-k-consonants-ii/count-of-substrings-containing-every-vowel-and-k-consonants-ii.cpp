class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    long long count(string s,int k) {
        int n = s.size();

        int i = 0, j = 0;
        int consonants = 0, vowels = 0;
        vector<int> nums(26,0);
        long long ans = 0;

        while(j < n) {
            // cout << consonants << endl;
            char ch = s[j];
            if(isVowel(ch)) {
                nums[ch-'a']++;
            }else {
                consonants++;
            }
            bool check = false;
            if(nums['a'-'a'] && nums['e'-'a'] && 
               nums['i'-'a'] && nums['o'-'a'] && 
               nums['u'-'a']
            ) {
                check = true;
            }
            while(check && consonants >= k) {
                ans += (n-j);
                if(isVowel(s[i])) {
                    nums[s[i]-'a']--;
                } else {
                    consonants--;
                }
                check = nums['a'-'a'] && nums['e'-'a'] && 
               nums['i'-'a'] && nums['o'-'a'] && 
               nums['u'-'a'];
                i++;
            }
            j++;
        }
        return ans;
    }
public:
    long long countOfSubstrings(string word, int k) {
        long long res1 = count(word,k); // no of substrings
        long long res2 = count(word,k+1);
        cout << res1 << "  " << res2 << endl;
        return (res1-res2);
    }
};