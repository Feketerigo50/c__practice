class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int result = 0;
        // for(int i = 1; i < prices.size();i++){
        //     if(prices[i] > prices[i-1]){
        //         result += prices[i] - prices[i-1];
        //     }
        // }
        int cash = 0;
        int hold = -prices[0];

        for(int i = 1; i < prices.size(); i++){
            int prev_cash = cash;
            cash = max(cash, prices[i] + hold);
            hold = max(hold, prev_cash - prices[i]);
        }

        return cash;
    }
};