//Merge Sort
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int p, int q, int r);
void print(int arr[], int size);

int size = 10;

int main()
{
    //test array
    int nums[] = {20, 13, 4, 9, 34, 26, 70, 130, 88, 45};
    
    cout << "Unsorted: ";
    print(nums, size);
    
    merge_sort(nums, 0, size-1);
    
    cout << "Sorted: ";
    print(nums, size);
    
}

void merge_sort(int arr[], int left, int right) {

    if (left < right){
        //divisible
        int mid;
        mid = floor((left+right)/2);
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int p, int q, int r){
    
    int left_size = q-p+1;
    int right_size = r-q;
    int left[left_size]; //temp store the array
    int right[right_size];
    
    //left side
    cout << "Left: ";
    for(int i = 0; i < left_size; i++){
        left[i] = arr[p+i];
        cout << left[i] << " ";
    }
    cout <<endl;
    
    //right side
    cout << "Right: ";
    for(int i = 0; i < right_size; i++){
        right[i] = arr[1+q+i];
        cout << right[i] << " ";
    }
    cout <<endl;
    
    //merge
    int index_l = 0; 
    int index_r = 0;
    cout << "Here: " << "p: " << p << " r: " << r <<endl;
    for(int i = p; i <= r; i++){
        if(index_r < right_size && index_l < left_size){
            if(left[index_l] <= right[index_r]){
                arr[i] = left[index_l];
                //cout << left[index_l] <<endl;
                index_l++;
            }
            else{        
                arr[i] = right[index_r];
                //cout << right[index_r] <<endl;
                index_r++;
            }
        }else if(index_r >= right_size){
                arr[i] = left[index_l];
                index_l++;
                //cout << left[index_l] << endl;
        }else if(index_l >= left_size){
                arr[i] = right[index_r]; 
                index_r++;
                //cout << right[index_r] <<endl;
        }
    }
    print(arr, size);
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout <<endl; 
}

