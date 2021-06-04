/**
 * @file stack_linkedlist_implementation.cpp
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
struct Node{
    int data;
    struct Node *next;
};
struct Node *top=NULL;

void push(int num){
    Node *t=new Node();
    t->data=num;
    t->next=top;
    top=t;
    cout<<"Element inserted successfully...\n";
}

void pop(){
    if(!top){
        cout<<"Stack is Empty...\n";
        return;
    }
    Node *temp=top;
    top=top->next;
    free(temp);
    cout<<"Element popped Successfully...\n";
}

void display(){
    if(top==NULL){
        cout<<"stack is Empty...\n";
        return;
    }
    Node *t=top;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
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