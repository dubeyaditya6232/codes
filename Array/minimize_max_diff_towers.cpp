// heights can not be negative after modification.
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
int n,k;
cin>>n>>k;
read(arr,n);
vector<pair<int,int> >V;
vi vis(n,0);
for(int i=0;i<n;i++){
    if(arr[i]<k){
        V.pb({arr[i]+k,i});
    }else{
        V.pb({arr[i]-k,i});
        V.pb({arr[i]+k,i});
    }
}
/* for(auto i : V){
    cout<<i.first<<" "<<i.second<<endl;
} */
sort(V.begin(),V.end());
int right=0,ele=0,left=0;
int m=INT32_MAX;
while(right<V.size()){
    while(ele<n && right<V.size()){
       if(vis[V[right].second]==0){
           ele++;
       }
       vis[V[right].second]++;
       right++;
    }
    if(ele<n)
    break;
    m=min(m,V[right-1].first-V[left].first);
    //cout<<V[right-1].first<<" "<<V[left].first<<" "<<m<<endl;
    if(vis[V[left].second]==1)
    ele--;

    vis[V[left].second]--;
    left++;
}
cout<<m<<endl;
return 0;
}