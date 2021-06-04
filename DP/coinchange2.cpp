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
   ll n,m;
   cin>>n>>m;
   read(arr,m);



   cout<<"Time Complexity: O(mn), auxillary space O(m*n)\n";
   ll dp[m+1][n+1];
   memset(dp,0,sizeof(dp));

   FOR(j,1,m+1)
   dp[j][0]=0;

   FOR(i,0,n+1)
   dp[0][i]=lmin;

   FOR(i,1,m+1){
       FOR(j,1,n+1){
           if(arr[i-1]>j){
               dp[i][j]=dp[i-1][j];
           }
           else{
               dp[i][j]=min(dp[i-1][j],1LL+dp[i][j-arr[i-1]]);
           }
       }  
   }
   cout<<dp[m][n]<<endl;
   cout<<"Time Complexity: O(mn), auxillary space O(n)\n";
   ll dp1[n+1];
   FOR(i,0,n+1)
   dp1[i]=lmin;
   dp1[0]=0;
   FOR(i,1,n+1){
       FOR(j,0,m){
           if(arr[j]<=i){
              ll ans=dp1[i-arr[j]];
              if(ans!=lmin && ans+1<dp1[i])
              dp1[i]=ans+1;
           }
       }
   }
   if(dp1[n]==lmin)
   cout<<"The required sum can't be obtained\n";
   else
   cout<<dp1[n]<<endl;
return 0;
}