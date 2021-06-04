/**
 * @file stack_array_implementation.c++
 * @author Aditya Kumar Dubey
 * @brief 
 * @version 0.1
 * @date 2021-06-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define max 100
int arr[max];
int top=-1;

void push(int num){

    if(top==max)
    {
        cout<<"stack is full\n";
        return;
    }
    top++;
    arr[top]=num;
     cout<<"Element pushed successfully\n";
}

void pop(){
    if(top==-1){
        cout<<"stack is already empty...\n";
        return;
    }
    top--;
    cout<<"Element popped successfully\n";
}
void display(){
    if(top==-1){
        cout<<"stack is empty...\n";
        return;
    }
    for(int i=top;i>=top;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
int ch,n;
while(1){
    cout<<"1.push\n2.pop\n3.display\n4.exit\n";
    cin>>ch;
    switch(ch){
        case 1:
        cin>>n;
        push(n);
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        break;
        default:
        cout<<"Not a Valid Choice !!\n";
        break;
    }
    cout<<"press 1 to continue\n";
    int choice;
    cin>>choice;
    if(choice==1)
    continue;
    else
    exit(0);
    
}
return 0;
}