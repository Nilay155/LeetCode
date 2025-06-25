typedef unsigned long long ll;
class Solution {
private:
    int count = 0;
private:
    bool baseConversion(ll num,ll base) {
        // cout << num << endl;
        string res;
        while(num) {
            ll rem = num%base;
            res.push_back((rem + '0'));
            num /= base;
        }
        // cout << res << endl;
        int i = 0, j = res.size()-1;
        while(i <= j) {
            if(res[i] != res[j]) return false;
            i++,j--;
        }
        return true;
    }
private:

    void solve(int base,int n,bool start,int i,int j,string front,string back, ll &ans) {   
        if(count >= n) return;
        if(i >= j) {
            string temp = back;
            reverse(temp.begin(),temp.end());
            if(i == j) {
                
                for(int k = 0 ; k <= 9 ; k++) {
                    if(k == 0 && start) continue;
                    ll num = stoll(front + to_string(k) + temp);
                    if(baseConversion(num,base)) {
                        ans += num;
                        count += 1;
                        // cout << num << endl;
                        if(count >= n) return;
                    }
                }   
            } else {
                    ll num = stoll(front + temp);
                    if(baseConversion(num,base)) {
                        ans += num;
                        count += 1;
                        // cout << num << endl;
                        if(count >= n) return;
                    }
            } 
            return;
        }
        
        for(int k = 0 ; k <= 9 ; k++) {
            if(k == 0 && start) continue;
 
            solve(base,n,false,i+1,j-1,front + to_string(k),
                back + to_string(k),ans);
        }

    }
public:
    long long kMirror(int k, int n) {
        ll ans = 0;
        for(int j = 0, i = 0 ; j <= 19 ; j++) {
            solve(k,n,true,i,j,"","",ans);
        }
        return ans;

    }
};