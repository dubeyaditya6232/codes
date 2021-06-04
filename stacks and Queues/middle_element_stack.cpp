/**
 * @file middle_element_stack.cpp
 * @author Aditya Dubey
 * @brief getMiddle and DeleteMiddle in O(n) time complexity(using recursion)
 * @version 0.1
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int getmiddlerecursion(int size)
{
    if (s.empty())
    {
        return INT_MIN;
    }
    if (size == 1)
        return s.top();

    int temp = s.top();
    s.pop();
    int ans = getmiddlerecursion(size - 1);
    s.push(temp);
    return ans;
}

void deleteMiddle(int size)
{
    if (s.empty())
    {
        cout << "stack is Empty\n";
        return;
    }

    if (size == 1)
    {
        s.pop();
        cout<<"Element deleted successfully\n";
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMiddle(size - 1);
    s.push(temp);
}

void display()
{
    cout << "Display not supported in this version\n";
}

int main()
{
    int ch, n,m;
    while (1)
    {
        cout << "1.push\n2.pop\n3.display\n4.getmiddle\n5.delete middle\n6.exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cin >> n;
            s.push(n);
            break;
        case 2:
            if(!s.empty())
            {
                s.pop();
                cout<<"element popped successfully\n";
            }
            else
            cout<<"stack  is empty\n";
            break;
        case 3:
            display();
            break;
        case 4:
            m = getmiddlerecursion((s.size() + 1) / 2);
            if (m != INT_MIN)
                cout << "middle Element is : " << m<<endl;
            else
            cout<<"stack  is empty\n";
            break;
        case 5:
            deleteMiddle((s.size() + 1) / 2);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Not a Valid Choice !!\n";
            break;
        }
        cout << "press 1 to continue\n";
        int choice;
        cin >> choice;
        if (choice == 1)
            continue;
        else
            exit(0);
    }
    return 0;
}