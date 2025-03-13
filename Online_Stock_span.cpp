class StockSpanner {
public:
    stack<pair<int, int>> st;  // Stack stores {price, span}

    StockSpanner() {}

    int next(int price) {
        int span = 1;  // Minimum span is always 1

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // Accumulate span of previous prices
            st.pop();
        }

        st.push({price, span});  // Push current price with its span
        return span;
    }
};
