#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> v = {1000,500,100,50,20,10,5,2,1};
    int coins = 0;
    int i = 0;
    while(amount > 0){
        coins += amount/v[i];
        amount %= v[i];
        i++;
    }
    return coins;
}
