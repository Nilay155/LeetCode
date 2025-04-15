class Solution {
private:
    long long maxK = 1000001;
    long long binomial(int n,int k) {
        // nCr
        if(k > n) return 0;
        if(k > n-k) k = n-k;
        long long res = 1;
        for(int i = 1 ; i <= k ;i++) {
            res = res * (n-i+1)/i;
            if(res >= maxK) return maxK;
        }
        return res;
    }
    long long multionmial(vector<int> &halfCounts) {
        int sum = 0;
        for(int cnt : halfCounts) sum += cnt;
        
        long long res = 1;
        for(int i = 0 ; i < 26 ; i++) {
            int cnt = halfCounts[i];
            res = res * binomial(sum,cnt);
            if(res >= maxK) return maxK;
            sum -= cnt;
        }
        return res;
    }
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> count(26,0);
        for(char ch : s) count[ch-'a']++;

        int half = 0;
        int oddChar = -1;
        vector<int> halfCount(26,0);

        for(int i = 0 ; i < 26 ; i++) {
            if(count[i]%2 == 1) oddChar = i;
            halfCount[i] = count[i]/2;
            half += halfCount[i];
        }

        long long totalPermutations = multionmial(halfCount);
        if(totalPermutations < k) return "";

        string front;
        for(int i = 0 ; i < half ; i++) {
            for(int j = 0 ; j < 26 ; j++) {
                if(halfCount[j]) {
                    halfCount[j]--;
                    long long permutations = multionmial(halfCount);

                    if(permutations >= k) {
                        front += (j + 'a');
                        break;
                    } else {
                        k -= permutations;
                        halfCount[j]++;
                    }
                }
            }
        }

        string rear = front;
        reverse(rear.begin(),rear.end());
        if(oddChar != -1) front += (oddChar + 'a');
        return front + rear;
    }
};