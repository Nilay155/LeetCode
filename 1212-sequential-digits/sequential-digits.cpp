class Solution {
private:
    vector<int> result;
    int l,h;
    void f(int prev,string &s) {
        
        for(int d = 1 ; d <= 9 ; d++) {
            if( prev + 1 == d  
                && ((s.empty() ? 0 : stoi(s)) * 10 + d) <= h) 
                {
                    s.push_back(d + '0');
                    if(stoi(s) >= l)
                        result.push_back(stoi(s));
                    f(d,s);
                    s.pop_back();
                }
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        l = low, h = high;
        string s;
        for(int i = 1 ; i <= 10 ; i++) {
            f(i - 1,s);
        }
        sort(result.begin(),result.end());
        return result;

    }
};