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


//recursive approach
ll solve(vi &V,vi &W,ll w,ll n){

    if(n==0 || w==0)
    return 0;

    if(W[n-1]>w)
    return solve(V,W,w,n-1);

    return max(V[n-1]+solve(V,W,w-W[n-1],n-1),solve(V,W,w,n-1));

}

// memoization approach
ll dp1[1000][1000];
ll solveDP1(vi &V,vi &W,ll w,ll n){
    if(n==0 || w==0)
    return 0;

    if(dp1[n][w]!=-1)
    return dp1[n][w];

    if(W[n-1]>w)
    dp1[n][w]=solveDP1(V,W,w,n-1);
    else
    dp1[n][w]=max(V[n-1]+solveDP1(V,W,w-W[n-1],n-1),solveDP1(V,W,w,n-1));
    
    return dp1[n][w];
}

// tabulation approach
ll solveDP(vi &V,vi &W,ll w,ll n){
    ll dp[n+1][w+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
           if(i==0 || j==0)
           dp[i][j]==0;
           else if(W[i-1]>j)
           dp[i][j]=dp[i-1][j];
           else
           dp[i][j]=max(V[i-1]+dp[i-1][j-W[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][w];
}


int main(){
    go();
ll n,w;
cin>>n>>w;
read(V,n);
read(W,n);

cout<<"recursive solution : ";
cout<<solve(V,W,w,n);
memset(dp1,-1,sizeof(dp1));
cout<<"\nDP Memoization solution : ";
cout<<solveDP1(V,W,w,n);
cout<<"\nDP Tabulation solution : ";
cout<<solveDP(V,W,w,n);

return 0;
}