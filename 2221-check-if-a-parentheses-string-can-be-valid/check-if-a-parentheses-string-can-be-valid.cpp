class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        stack<int> open,wildCard;

        for(int i = 0 ; i < n ; i++) {
            if(locked[i] == '0') wildCard.push(i);
            else if(s[i] == '(') open.push(i);
            else {
                if(!open.empty()) open.pop();
                else if(!wildCard.empty()) wildCard.pop();
                else return 0;
            }
        }

        while(!wildCard.empty() && !open.empty()) {
            int top1 = open.top();
            int top2 = wildCard.top();
            open.pop();
            wildCard.pop();

            if(top1 > top2) return 0; 
        }
        return wildCard.size()%2 == 0 && open.empty();
    }
};