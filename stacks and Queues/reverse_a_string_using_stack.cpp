/**
 * @file reverse_a_string_using_stack.cpp
 * @author Aditya Kumar Dubey
 * @brief  O(n) space and time complexity.
 * @version 0.1
 * @date 2021-06-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;
void go() {
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
 freopen("../input.txt", "r", stdin);
 freopen("../output.txt", "w", stdout);
#endif
}

int main(){
    go();
string s;
getline(cin,s);
cout<<"Original string is : "<<s<<endl;

stack<char>st;
for(int i=0;i<s.length();i++){
    st.push(s[i]);
}
string rev;
while(!st.empty()){
    char ch=st.top();
    rev+=ch;
    st.pop();
}
cout<<"Reverse of the string is : ";
cout<<rev<<endl;
return 0;
}