class StockSpanner {
private:
    vector<int> prices;
    vector<int> st;

public:
    StockSpanner() {
                
    }
    
    int next(int price) {
        int i = prices.size();
        prices.push_back(price);

        while(!st.empty() && prices[st.back()] <= price) {
            st.pop_back();
        }
        int span;

        if(st.empty()) {
            span = i + 1;
        } else {
            span = i - st.back();
        }
        st.push_back(i);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */