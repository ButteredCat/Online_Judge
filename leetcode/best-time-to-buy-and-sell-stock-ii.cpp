/**
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at
 * the same time (ie, you must sell the stock before you buy again).
 */

class Solution {
public:
    int maxProfit (vector<int> &prices) {
        int max_profit = 0;

        if (prices.size() > 0) {
            for (vector<int>::size_type i = 0; i < prices.size() - 1; ++i) {
                if (prices[i + 1] > prices[i]) {
                    max_profit += prices[i + 1] - prices[i];
                }
            }
        }

        return max_profit;
    }
};

class Solution_2 {
public:
    // A simulation for the real trade. If you sell in day i, you cannot buy until day i+1.
    int maxProfit (vector<int> &prices) {
        int max_profit = 0;

        if (prices.size() > 1) {
            int lowest = prices[0];
            bool onTrans = (prices[0] < prices[1]);
            vector<int>::size_type i = 1;

            for ( ; i != prices.size() - 1; ++i) {
                // Find local maximum. If found, sell.
                if (onTrans && prices[i] >= prices[i - 1] && prices[i] >= prices[i + 1]) {
                    max_profit += prices[i] - lowest;
                    onTrans = false;
                }
                // Find local minimum. If found, buy.
                else if (prices[i] <= prices[i - 1] && prices[i] <= prices[i - 1] ) {
                    lowest = prices[i];
                    onTrans = true;
                }
            }

            if (onTrans && prices[i] >= prices[i - 1]) {
                max_profit += prices[i] - lowest;
            }
        }

        return max_profit;
    }
};
