// median of two sorted array of different sizes.

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
read(V1,n);
read(V2,m);
int i=0,j=0;
if((n+m)%2!=0){
    int c=0,m1;
    while(c<=(n+m)/2){
        if(i!=n && j!=m){
            if(V1[i]<V2[j])
            m1=V1[i++];
            else
            m1=V2[j++];
        }
        else if(i<n)
        m1=V1[i++];
        else
        m1=V2[j++];
        c++;
    }
}else{
    int m1=0,m2=0,c=0,i=0,j=0;
    while(c<=(n+m)/2){
        m2=m1;
        if(i!=n && j!=m){
            if(V1[i]<V2[j])
            m1=V1[i++];
            else
            m1=V2[j++];
        }
        else if(i<n)
        m1=V1[i++];
        else
        m1=V2[j++];
        c++;
    }
    //cout<<m1<<" "<<m2<<endl;
    float ans=(m1+m2)/2;
    cout<<ans<<endl;
}

return 0;
}