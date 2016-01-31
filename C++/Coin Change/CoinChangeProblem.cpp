// Example program
#include <iostream>
#include <string>

using namespace std;


int coin_change_possibility(int amount, int coins[], int coin_size);
int possible_ways(int current_amount, int possible_arr[], int coins[], int coin_size);

int main()
{
    int n, m;
    cin >> n >> m; 
    
    int coins[m]; 
    for(int i = 0; i < m; i++){
        cin >> coins[i];
    }
    
    int possibilities; 
    possibilities = coin_change_possibility(n, coins, m);
    
    cout << possibilities;
    
}


int coin_change_possibility(int amount, int coins[], int coin_size){
    
    int possible_arr[amount] = {0}; //array to keep track of the possible way for each number from 1-N;
        
    int possibilities = possible_ways(amount, possible_arr, coins, coin_size);
    
    return possibilities; 
}


int possible_ways(int current_amount, int possible_arr[], int coins[], int coin_size){
    
    cout << "Current Amount: " << current_amount <<endl;    
        
    //if it has already been calculated
    if(possible_arr[current_amount-1]){
        return possible_arr[current_amount-1];
    }
    
    //else: 
    int possibilities = 0; 
    
    //find new case
    for(int i = 0; i < coin_size; i++){
        if(current_amount == coins[i]){
            possibilities++;
        }
    }

    //find combinations
    int start_amount = 1; 
    int end_amount = current_amount - 1;
    while(start_amount <= end_amount){
        possibilities += (possible_ways(start_amount, possible_arr, coins, coin_size)*possible_ways(end_amount, possible_arr, coins, coin_size));
        start_amount++; 
        end_amount--;
    }
    
    possible_arr[current_amount-1] = possibilities; //store data here
    
    cout << "Possibilities: " << possibilities <<endl;
    
    return possibilities;
}

