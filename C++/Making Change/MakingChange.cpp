//Making Change
//You are given n types of coin denominations of values v(1) < v(2) < ... < v(n) (all integers). 
//Assume v(1) = 1, so you can always make change for any amount of money C. 
//Give an algorithm which makes change for an amount of money C with as few coins as possible

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int make_change(int amount, int coins[], int i);

int main()
{
    int n;
    cin >> n;
    
    int amount; 
    cin >> amount;
    
    int* coins = new int[n];
    for(int i = 0; i< n; i++){
        cin >> coins[i];
    }
    
    int min_num = make_change(amount, coins, n-1);
    
    cout << min_num;
    
    delete coins;
}

int make_change(int amount, int coins[], int i){
    
    //assuming i is sorted already
    
    if(amount <= 0){
        return 0;
    }
    
    int coins_num = 0;  
    
    if(coins[i] <= amount){
        coins_num += floor(amount/coins[i]) + make_change(amount%coins[i], coins, i-1);   
    }else{
        coins_num += make_change(amount, coins, i-1);
    }
    
    return coins_num;
}

