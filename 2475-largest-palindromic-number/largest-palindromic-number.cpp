class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int> count(10,0);
        for(char ch : num) count[ch - '0'] += 1;

        string front,rear;
        for(int i = 9 ; i >= 1 ; i--) {

            while(count[i] > 1) {
                front.push_back(i + '0');
                rear.push_back(i + '0');
                count[i] -= 2;
            }
        }

        // edge-case of '0' can be a leading element
        if(count[0] > 1) {
            if(!front.empty()) {
                while(count[0] > 1) {
                    front.push_back('0');
                    rear.push_back('0');
                    count[0] -= 2;
                }
            } else {
                count[0] = 1;
            }
        }

        // now all the count of integers is either 1 or 0
        int largest = -1;
        for(int i = 0 ; i < 10 ; i++) {
            if(count[i] == 1) largest = i;
        } 
        if(largest != -1)
            front.push_back(largest + '0');
        reverse(rear.begin(),rear.end());
        return front + rear;
    }
};