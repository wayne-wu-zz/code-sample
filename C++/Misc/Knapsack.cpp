//Knapsack:
//Given a list of n integers, A={a1,a2,…,an},
//and another integer, k representing the expected sum. 
//Select zero or more numbers from A 
//such that the sum of these numbers is as near as possible, 
//but not exceeding, to the expected sum (k).

#include <iostream>
#include <string>

using namespace std;

int nearest_k(int nums[], int size, int expected_sum);

int main()
{
    int n, k;
    
    int* nums = new int[n];
    
    for(int i =0; i<n; i++){
        cin >> nums[i];
    }
    
    int ans = nearest_k(nums, n, k);
    cout << ans <<endl;
    
}

int nearest_k(int nums[], int size, int expected_sum){
    
    //O(n)
    for(int i = 0; i < size; i++){
        if(expected_sum%nums[i] ==0){
            return expected_sum; 
        }
    }
    
    //O(nlogn)
    //TODO: merge_sort(expected_sum); 
    
    //O(n)
    int sum = 0;
    int nearest_sum = 0;
    for(int i = 0; i<size; i++){
        sum += nums[i]; 
        if(sum <= expected_sum){
            nearest_sum = sum;
        }else{
            break;
        }
    }
    return nearest_sum;  
}