/**
 * @file balanced_paranthesis.cpp
 * @author Aditya Kumar Dubey
 * @brief turned it into balanced brackets to check if it passes the test cases of hackerrank
 * @version 0.1
 * @date 2021-06-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lprint(n) printf("%lld", n)
#define print(n) printf("%d", n)
#define println(n) printf("%d\n", n)
#define lprintln(n) printf("%lld\n", n)
#define FOR(i, init, n) for (int i = init; i < n; i++)
#define pb push_back
#define mp make_pair
#define lmax LLONG_MIN
#define lmin LLONG_MAX
#define vi vector<ll>
#define mii map<ll, ll>
#define mci map<char, ll>
#define read(arr, n) vector<ll> arr(n);for (ll i = 0; i < n; i++)cin >> arr[i];
#define prt(arr, n) for (ll i = 0; i < n; i++)cout << arr[i] << ' ';
const int mod = 1e9 + 7;
const int N = 1e6 + 4;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}
ll add(ll a, ll b){
 ll c = a + b;
 c = c % mod;
 return c;
}
ll noOfDigits(ll n){
 int c = 0;
 while (n > 0){
     c++;
     n /= 10;
 }
 return c % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}

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
cin>>s;
if(s[0]==')' || s.back()=='(')
cout<<"NO\n";
else{
    stack<char>st;
    int c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{'|| s[i]=='[')
        st.push(s[i]);
        else{
            if(st.empty()){
                c=1;
                break;
            }
            else{
                if(s[i]==')' && st.top()=='(')
                st.pop();
                else if(s[i]=='}' && st.top()=='{')
                st.pop();
                else if(s[i]==']' && st.top()=='[')
                st.pop();
                else{
                    c=1;
                    break;
                }
            }
        }
    }
    if(c==1 || !st.empty())
    cout<<"NO\n";
    else
    cout<<"YES\n";
}
return 0;
}