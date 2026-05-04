class StockSpanner {
private:
    stack<pair<int,int>> st;
    int pos = 0;
public:
    StockSpanner() {
        this -> pos = 0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price)
            st.pop();
        
        int ans = 0;
        if(!st.empty()) ans = pos - st.top().second + 1;
        else ans = pos + 1;

        st.push({price,++pos});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */