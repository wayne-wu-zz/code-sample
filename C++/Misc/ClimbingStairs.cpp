//You are climbing a stair case. 
//It takes n steps to reach to the top. 
//Each time you can either climb 1 or 2 steps. 
//In how many distinct ways can you climb to the top?

#include <iostream>
#include <string>

using namespace std;

int num_ways(int stairs, int *ways);

int main()
{
    int num; 
    cin >> num;
    
    int *ways = new int[num]();
    
    int i;
    i = num_ways(num, ways);
    
    cout << i;
    
    delete ways;
}

int num_ways(int stairs, int *ways){
    
    //cout << "Stairs: " << stairs << endl; 
    
    //memo-ization
    if(ways[stairs-1]){
        return ways[stairs-1];
    }
    
    //Base Case: 1 and 0
    if(stairs == 1){
        return 1;
    }
    if(stairs == 0){
        return 1;
    }
    
    ways[stairs-1] = num_ways(stairs-1, ways) + num_ways(stairs-2, ways);
    
    //cout << "Ways: " << ways[stairs-1] << endl; 
    
    return ways[stairs-1];    
    
}