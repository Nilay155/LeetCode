class StockSpanner {
private:
    stack<int> st;
    vector<int> arr;
public:
    StockSpanner() {
        st.push(-1);
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && st.top() != -1 && arr[st.top()] <= price) {
            st.pop();
        }
        int ans = 0;
        if(st.top() == -1) ans = arr.size();
        else ans = arr.size()-st.top()-1;

        st.push(arr.size()-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */