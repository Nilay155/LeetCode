class Solution {
private:
    void checkDecimalPointNumbers(string &s,int &i,int &n,bool &f,bool &pf) {
        bool sf = false;   
        while(i < n && isdigit(s[i])) {
            i += 1;
            sf = true;
        }
        if(!pf && !sf) {
            f = false;
            return ;
        }
        if(i == n) 
            return ;

        if(s[i] == 'e' || s[i] == 'E') {
            f = true;
        } else {
            f = false;
        }
        return ;
    }
    void checkExponentNumber(string &s,int &i,int &n,bool &es,bool &en) {
        if(i == n) {
            en = false;
            return ;
        }

        if(s[i] == '-' || s[i] == '+') i += 1, es = true;
        if(i == n) {
            en = false;
            return ;
        }
        while(i < n && isdigit(s[i])) {
            i += 1;
        }

        if(i == n) en = true;
        else en = false;

        return ; 
    }
public:
    bool isNumber(string s) {
        bool firstSignCheck = true;
        bool firstNumberCheck = true;
        bool exponentSignCheck = true;
        bool exponentNumberCheck = true;
        
        int i = 0, n = s.length();
        if(s[0] == '+' || s[0] == '-')
            firstSignCheck = true, i += 1;
        
        if(i == n) return false;
        while(i < n && isdigit(s[i])) {
            i += 1;
        }
        // now either i is n and if not
        if(i < n) {
            if(s[i] == '.') { // getting a decimal number
                // we need a proper whole number from here
                bool pf = false;
                if(i-1 >= 0 && isdigit(s[i - 1])) pf = true;
                i += 1;
                checkDecimalPointNumbers(s,i,n,firstNumberCheck,pf);
                // cout << firstNumberCheck << "\n";
                if(i < n && firstNumberCheck) {
                    if(s[i] == 'E' || s[i] == 'e') {
                        i += 1;
                        checkExponentNumber(s,i,n,exponentSignCheck,exponentNumberCheck);
                    } else {
                        firstNumberCheck = false;
                    }
                }
            } else if(s[i] == 'E' || s[i] == 'e') { // exponent number
                if(i-1 < 0) 
                    exponentNumberCheck = false;
                else if(!isdigit(s[i - 1]))
                    exponentNumberCheck = false;
                else {
                    i += 1;
                    checkExponentNumber(s,i,n,exponentSignCheck,exponentNumberCheck);
                }
            } else { // an invalid character
                firstNumberCheck = false;
            }
        } 
        // cout << firstSignCheck << "  " << firstNumberCheck << "  " << exponentSignCheck << "  " << exponentNumberCheck << "\n";
    
        return ( firstSignCheck && firstNumberCheck && exponentSignCheck && exponentNumberCheck );
    }
};