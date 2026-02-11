class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # profit = 0
        # for i in range (len(prices)):
        #     for j in range(i+1,len(prices)):
        #         if (j > i)
        #             profit = prices[j] - prices[i]
        #             max_profit =max(max_profit,profit)
        # return max_profit
        buy_price = max(prices)
        sell_price = 0
        max_profit = 0
        for i in range(len(prices)):
            if buy_price > prices[i]:
                buy_price = prices[i]
            sell_price = prices[i]
            profit = sell_price - buy_price
            max_profit = max(max_profit,profit)
        return max_profit
