#include <bits/stdc++.h>
using namespace std;

int max_profit(vector<int> stock)
{
    int n = stock.size();
    int mini = stock[0];
    int maxprofit = 0;
    for(int i = 1; i < n; i++)
    {
        int profit = stock[i] - mini;
        maxprofit = max(profit, maxprofit);
        mini = min(mini, stock[i]);
    }
    return maxprofit;
}

int main(){
    cout << endl << "Enter the stock prices: ";
    vector<int> stock;
    int input;
    while(cin >> input)
        stock.push_back(input);
    cout << endl << "Maximum Profit: " << max_profit(stock);

    return 0;
}