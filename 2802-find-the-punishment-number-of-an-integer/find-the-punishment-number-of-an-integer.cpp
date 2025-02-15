class Solution {
private:
    bool isValid(int i,int target,int num,string &square) {
        if(i >= square.length() && target == num) return true;

        for(int j = i ; j < square.length() ; j++) {
            int temp = stoi(square.substr(i,j-i+1));
            if(isValid(j+1,target,num + temp,square)) return true;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int res = 1;

        for(int i = 2 ; i <= n ; i++) {
            int square = i*i;
            string str = to_string(square);
            if(isValid(0,i,0,str)) res += (square);
        }
        return res;
    }
};