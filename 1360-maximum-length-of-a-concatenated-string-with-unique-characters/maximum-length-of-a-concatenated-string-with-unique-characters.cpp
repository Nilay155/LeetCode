class Solution {
private:
    int maximumLength(vector<string> &strs,int mask,int i,int &n) {
        if(i >= n) {
            int length = 0;
            for(int i = 0 ; i < 32 ; i++) {
                if(mask & (1 << i)) {
                    length += 1;
                }
            }
            return length;
        }

        int notPick =  maximumLength(strs,mask,i+1,n);

        bool flag = false;
        int newMask = mask;
        for(int j = 0 ; j < strs[i].length() ; j++) {
            int k = strs[i][j] - 'a';
            if(newMask & (1 << k)) {
                flag = true;
                break;
            }
            newMask |= (1 << k);
        }
        int pick = 0;
        if(!flag) pick =  maximumLength(strs,newMask,i+1,n);

        return  max(pick,notPick);
    }

public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int mask = 0;
        return maximumLength(arr,mask,0,n);
    }
};