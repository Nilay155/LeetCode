class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd,even;
        int n = num;
        while(n) {
            int digit = n % 10;
            n /= 10;
            if(digit & 1) odd.push_back(digit);
            else even.push_back(digit);
        }

        sort(odd.rbegin(),odd.rend());
        sort(even.rbegin(),even.rend());

        int ans = 0,cnt = 0;
        while(num) {
            int digit = num % 10;
            num /= 10;

            if(digit & 1) {
                ans = odd.back() * pow(10,cnt) + ans;
                odd.pop_back();
            } else {
                ans =  even.back() * pow(10,cnt) + ans;
                even.pop_back();
            }
            cnt += 1;
        } 
        return ans;
    }
};