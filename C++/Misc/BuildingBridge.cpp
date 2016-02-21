// Example program
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int longest_common_subsequence(map<int, int>& north, map<int, int>& south, map<int, int>::iterator ii, map<int, int>::iterator jj);

int main()
{
    int cities;
    cin >> cities;
    
    map<int, int> north; 
    map<int, int> south;
    
    int xcoord;
    for(int i = 0; i < 0; i++){
        cin >> xcoord; 
        north[i] = xcoord; 
    }
    
    for(int i = 0; i < 0; i++){
        cin >> xcoord; 
        south[i] = xcoord; 
    }
    
    int num;
    
    num = longest_common_subsequence(north, south, north.end(), south.end());
    
    cout << num;
    
}

int longest_common_subsequence(map<int, int>& north, map<int, int>& south, map<int, int>::iterator ii, map<int, int>::iterator jj){
    
    //TODO: Memo-ization to avoid repeating work
    
    
    if(!(ii->first) || !(jj->first)){
        return 0;
    }
    
    int num = 0; //base case
    
    if(ii -> first == jj -> first)
        num = longest_common_subsequence(north, south, --ii, --jj) + 1; //
    else{
        num = max(longest_common_subsequence(north, south, --ii, jj), longest_common_subsequence(north, south, ii, --jj));  
    }
    
    return num;
    
}

