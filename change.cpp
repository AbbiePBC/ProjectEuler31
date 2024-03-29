#include "change.hpp"

Change::Change(int moneyInPence) {
    input_ = moneyInPence;
    coins_ = {200, 100, 50, 20, 10, 5, 2, 1};
    findWaysToMakeChange(input_, coins_, 0);
}


const int Change::findWaysToMakeChange(const int &moneyInPence, std::vector<int> coins, int coin_idx) {
    
    while (coins.at(coin_idx) > moneyInPence){
        coin_idx ++;
    }

    for (int i = coin_idx; i < coins.size(); i ++){
        int coin = coins.at(i);
        if (moneyInPence - coin == 0 || moneyInPence - coin == 0 || coin == 1){
            ++result_;
            continue;
        }
        findWaysToMakeChange(moneyInPence - coin, coins, i);
    }
    return result_;
}