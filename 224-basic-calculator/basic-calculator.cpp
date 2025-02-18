class Solution {
private:
    string removeSpaces(string &s) {
        string res;
        for (char c : s) {
            if (c != ' ') res.push_back(c);
        }
        return res;
    }

public:
    int calculate(string s) {
        s = removeSpaces(s);
        int n = s.size();
        stack<int> nums;
        stack<char> ops;
        int i = 0;

        while (i < n) {
            char ch = s[i];

            if (isdigit(ch)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // Adjust index after loop
                nums.push(num);
            } 
            else if (ch == '+' || ch == '-') {
                if (i == 0 || s[i - 1] == '(') { 
                    // Handle negation like "(-2)" or "( -2)"
                    nums.push(0);
                }
                while (!ops.empty() && ops.top() != '(') {
                    char op = ops.top(); ops.pop();
                    int num1 = nums.top(); nums.pop();
                    int num2 = nums.top(); nums.pop();
                    nums.push((op == '+') ? num1 + num2 : num2 - num1);
                }
                ops.push(ch);
            } 
            else if (ch == '(') {
                ops.push(ch);
            } 
            else if (ch == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    char op = ops.top(); ops.pop();
                    int num1 = nums.top(); nums.pop();
                    int num2 = nums.top(); nums.pop();
                    nums.push((op == '+') ? num1 + num2 : num2 - num1);
                }
                ops.pop(); // Remove '('
            }
            i++;
        }

        while (!ops.empty()) {
            char op = ops.top(); ops.pop();
            int num1 = nums.top(); nums.pop();
            int num2 = nums.top(); nums.pop();
            nums.push((op == '+') ? num1 + num2 : num2 - num1);
        }

        return nums.top();
    }
};
