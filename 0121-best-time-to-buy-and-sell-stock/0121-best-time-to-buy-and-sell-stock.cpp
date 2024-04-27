class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        st.push(prices[0]);
        int maxProfit = 0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>st.top()){
                maxProfit = max(maxProfit,prices[i]-st.top());
            }
            else{
                st.pop();
                st.push(prices[i]);
            }
        }
        return maxProfit;
    }
};