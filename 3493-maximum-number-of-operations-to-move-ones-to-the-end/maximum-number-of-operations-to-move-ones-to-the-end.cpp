class Solution {
public:
    int maxOperations(string s) {

        int n = s.length();
        int moves = 0, count = 0;
        int j = n - 1;

        while(j >= 0 && s[j] == '1') j--;
        vector<int> arr;
        for(int i = 0 ; i <= j ; i++) {
            if(s[i] == '1') {
                count += 1;
            } else {
                if(count)
                    arr.push_back(count);
                count = 0;
            }
        }
        if(count) 
            arr.push_back(count);
        count = 0;
        for(int i = 0 ; i < (int) arr.size() ; i++) {
            count += arr[i];
            moves += count;
        }
        return moves;
    }
};