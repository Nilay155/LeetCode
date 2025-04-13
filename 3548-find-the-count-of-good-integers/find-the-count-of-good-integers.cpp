class Solution {
private:
    long long factorial(int n) {
        long long fact = 1;
        for(int i = 1 ; i <= n ; i++) fact *= i;
        return fact;
    }
    long long permutations(map<int,int> &mpp,int k) {
        long long res = factorial(k);
        for(auto& it : mpp) res /= factorial(it.second);
        return res;
    }
    long long zeroPermutations(map<int,int> &mpp,int k) {
        bool flag = false;
        if(mpp.find(0) != mpp.end()) flag = true;

        if(flag) {
            long long res = factorial(k-1);
            for(auto& it : mpp) {
                if(it.first == 0) res /= factorial(it.second-1);
                else res /= factorial(it.second);
            }
            return res;
        }
        return 0;
    }
private:
    set<map<int,int>> st;
private:

    long long count(string str,int &k,int i,int j,int flag) {
        if(i > j) {
            // Base Case
            long long num = stoll(str);
            if(num%k == 0) {
                map<int,int> mpp;
                while(num) {
                    mpp[num%10]++;
                    num /= 10;
                }
                if(st.count(mpp)) return 0;
                st.insert(mpp);
                long long ans = permutations(mpp,str.size()) - zeroPermutations(mpp,str.size());
                
                return ans;
            }
            return 0;
        }
        long long res = 0;
        for(char ch = '0' ; ch <= '9' ; ch++) {
            if(ch == '0' && flag == 1) continue;
            
            str[i] = str[j] = ch;
            res += (count(str,k,i+1,j-1,0));            
        }
        return res;
    }
public:
    long long countGoodIntegers(int n, int k) {
        string str;
        for(int i = 0 ; i < n ; i++) str.push_back('_');

        return count(str,k,0,n-1,1);
    }
};