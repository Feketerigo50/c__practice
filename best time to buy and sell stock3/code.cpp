class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int never_buy = 0;
        int first_cash = 0;
        int first_hold = -prices[0];
        int second_cash = 0;
        int second_hold = -prices[0];
        for(int i = 1; i < prices.size();i++){
            first_hold = max(first_hold, never_buy - prices[i]);
            first_cash = max(first_cash, first_hold + prices[i]);
            second_hold = max(second_hold, first_cash - prices[i]);
            second_cash = max(second_cash, second_hold + prices[i]);
        }

        return max({never_buy, first_cash, second_cash});
    }
};