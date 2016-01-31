//Linked List Example

#include <iostream>
#include <string>

using namespace std; 

struct node{
    int data;
    node* next;
}; 


int main()
{
    node* n = new node; 
    n -> data = 1; 
    
    node* temp = n; 
    node* head = n; //access starting point
    
    n = new node; 
    n -> data = 2; 
    temp -> next = n; 
    temp = temp -> next; 
    
    n = new node; 
    n -> data = 3;
    temp -> next = n;
    temp = temp -> next; 
    
    
    n = new node; 
    n -> data = 4; 
    temp -> next = n;
    n -> next = nullptr; //end here
    
    node* t = head; 
    for(int i = 0; i < 4; i++){
        cout << t-> data; 
        t = t -> next;
    }
    
}
