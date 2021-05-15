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
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
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
read(V2,n);
read(V1,m);
vector<int>V3,V4;
int i=0,j=0;
while(i<m && j<n){
    if(V1[i]<V2[j])
    V3.pb(V1[i++]);
    else if(V1[i]>V2[j])
    V3.pb(V2[j++]);
    else
    {
        V3.pb(V2[j++]);
        i++;
    }
}
while(i<m)
V3.pb(V1[i++]);
while(j<n)
V3.pb(V2[j++]);

cout<<"Union of sorted two array is : ";
prt(V3,V3.size());
i=0,j=0;
while(i<m && j<n){
    if(V1[i]<V2[j])
    i++;
    else if(V1[i]>V2[j])
    j++;
    else
    {
        V4.pb(V2[j++]);
        i++;
    }
}
cout<<"\nIntersection of sorted two array is : ";
prt(V4,V4.size());

return 0;
}