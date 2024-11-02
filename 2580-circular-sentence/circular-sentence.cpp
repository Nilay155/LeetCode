class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> arr;
        string temp;
        for(char ch : sentence) {

            if(ch == ' ') {
                arr.push_back(temp);
                temp = "";
            } else {
                temp.push_back(ch);
            }
       }
        arr.push_back(temp);
        int n = arr.size();
        
        string front,back;
        for(int i = 1 ; i < n ; i++) {
            front = arr[i];
            back = arr[i-1];

            if(front[0] != back.back()) return 0;
        }
        front = arr[n-1];
        back = arr[0];
        if(front.back() != back[0]) return 0;
        return 1;
    }
};


