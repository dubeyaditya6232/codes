#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lprint(n) printf("%lld", n)
#define print(n) printf("%d", n)
#define newline() printf("\n")
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
void go() {
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
 freopen("../input.txt", "r", stdin);
 freopen("../output.txt", "w", stdout);
#endif
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

int main(){
go();
int n,m;
cin>>n>>m;
read(v1,n);
read(v2,n);
map<int,int>M;
int c=0;
if(n>m){
    for(int i=0;i<n;i++){
        M[v1[i]]++;
    }
    for(int i=0;i<m;i++){
        if(M[v2[i]]!=0)
        M[v2[i]]--;
        else{
            c=1;
            break;
        }
    }
}
else{
    for(int i=0;i<m;i++){
        M[v2[i]]++;
    }
    for(int i=0;i<n;i++){
        if(M[v1[i]]!=0)
        M[v1[i]]--;
        else{
            c=1;
            break;
        }
    }
}
if(c==0)
cout<<"YES array is a subset of another array";
else
cout<<"NO array is not a subset of another array";
return 0;
}