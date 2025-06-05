class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        // vector<bool> left(n,false), right(n,false),arr(n,false);
        deque<int> dq;    

        for(int i = n-1 ; i >= 0 ; i--) {
            char ch = dominoes[i];
            if(ch == 'R') {
                if(dq.empty()) {
                    int x = i+1;
                    while(dominoes[x] == '.' && x < n) {
                        dominoes[x] = 'R';
                        x++;
                    }
                    continue;
                }
                int end = dq.front(); dq.pop_front();
                int s = i+1, e = end-1;
                
                while(s < e) {
                    bool flag = false;
                    if(dominoes[s] == '.') {
                        dominoes[s] = 'R';
                        s++;
                        flag = true;
                    }
                    if(dominoes[e] == '.') {
                        dominoes[e] = 'L';
                        e--;
                        flag = true;
                    }
                    if(!flag) break;
                }
            } else if(ch == 'L') {
                dq.push_front(i);
            }
        }

        while(!dq.empty()) {
            int back = dq.back(); dq.pop_back();
            back--;
            while(back >= 0 && dominoes[back] == '.') {
                dominoes[back] = 'L';
                back--;
            }
        }
        return dominoes;
    }
};