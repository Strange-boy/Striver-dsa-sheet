#include <bits/stdc++.h>
using namespace std;

//optimal solution to solve the problem
int optimalBuyAndSellStocks(vector<int> &prices){
    int maxProfit = 0;
    int minStockPrice = prices[0];

    for(auto sellingPrice: prices){
        int profit = sellingPrice - minStockPrice;
        if(maxProfit < profit) maxProfit = profit;

        if(minStockPrice > sellingPrice) minStockPrice = sellingPrice;
    }

    return maxProfit;
}

//max profit generated
int bruteBuyAndSellStocks(vector<int> &prices){
    int maxPrice = 0;

    //O(N^2) approach to solve the problem
    for(int buyingDay = 0; buyingDay < prices.size(); buyingDay += 1){
        for(int selllingDay = buyingDay + 1; selllingDay < prices.size(); selllingDay += 1){
            int currPrice = prices[selllingDay] - prices[buyingDay];
            if(maxPrice < currPrice) maxPrice = currPrice;
        }
    }

    return maxPrice;
}

int main(){
    int length;
    cin >> length;

    vector<int> stockPrice(length);

    //enter the stock price
    for(auto &price: stockPrice){
        cin >> price;
    }

    int maxProfit = optimalBuyAndSellStocks(stockPrice);

    cout << maxProfit << '\n';
}