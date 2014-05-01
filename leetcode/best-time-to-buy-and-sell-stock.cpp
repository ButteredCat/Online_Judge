/**
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 */

class Solution {
public:
    int maxProfit (vector<int> &prices) {
        int max_price = 0;
        int max_profit = 0;

        for (vector<int>::reverse_iterator iv = prices.rbegin(); iv != prices.rend(); ++iv) {
            if (max_price - *iv >= max_profit) {
                max_profit = max_price - *iv;
            } else if (*iv > max_price ) {
                max_price = *iv;
            }
        }

        return max_profit;
    }
};
