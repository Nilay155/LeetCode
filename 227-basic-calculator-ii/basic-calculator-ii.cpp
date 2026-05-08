class Solution {
private:
    unordered_map<char,int> precedence;
public:
    Solution() {
        precedence.clear();
        precedence['-'] = precedence['+'] = 1;
        precedence['*'] = precedence['/'] = 2;
    }
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> numbers;
        stack<char> operators;

        int i = 0;
        while(i < n) {
            int currNum = 0;
            bool flag = false;
            while(i < n && isdigit(s[i])) {
                flag = true;
                currNum = currNum * 10 + (s[i] - '0');
                i += 1;
            }
            if(flag)
                numbers.push(currNum);

            // Ignoring Spaces
            while(i < n && s[i] == ' ') {
                i += 1;
            }

            // Handling Operators
            if(i < n && !isdigit(s[i]) && s[i] != ' ') {
                if(operators.empty()) {
                    operators.push(s[i]);
                } else {
                    int p1 = precedence[operators.top()];
                    int p2 = precedence[s[i]];

                    while(p1 >= p2) {
                        int n2 = numbers.top(); numbers.pop();
                        int n1 = numbers.top(); numbers.pop();
                        char opr = operators.top(); operators.pop();

                        if(opr == '-') numbers.push(n1 - n2);
                        else if(opr == '+') numbers.push(n1 + n2);
                        else if(opr == '*') numbers.push(n1 * n2);
                        else numbers.push(n1 / n2);

                        if(!operators.empty()) p1 = precedence[operators.top()];
                        else p1 = 0;
                    }
                    operators.push(s[i]);
                }
                i += 1;
            }
        }
        while(!operators.empty()) {
            int n2 = numbers.top(); numbers.pop();
            int n1 = numbers.top(); numbers.pop();
            char opr = operators.top(); operators.pop();
                        

            if(opr == '-') numbers.push(n1 - n2);
            else if(opr == '+') numbers.push(n1 + n2);
            else if(opr == '*') numbers.push(n1 * n2);
            else numbers.push(n1 / n2);
        }
        return numbers.top();
    }
};