
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
ll n, m;
pi a[105];
ll dp[55005];
int main(){
    memset(dp, 0x3f, sizeof dp);
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        cin >> a[i].f >> a[i].s;
        }   
    ll ans = LLONG_MAX;
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=a[i].f;j<=m+5000;j++){
            dp[j] = min(dp[j], dp[j-a[i].f]+a[i].s);
            if(j>=m&&dp[j]<ans)ans=dp[j];
        }
    }
    cout << ans << "\n";
    return 0;
}