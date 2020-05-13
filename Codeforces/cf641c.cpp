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
using namespace std;
typedef long long ll;
ll n, a[100005];
vector<ll> s[200005];
ll zcnt[200005], cnt[200005];
ll mx=0;
void primeFac(ll n)  
{  
 
map<ll, ll> m;
    while (n % 2 == 0)  
    {  
        m[2]++;
        n = n/2;  
    }  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            m[i]++;
            n = n/i;  
        }  
    }   
    if (n > 2)  
        m[n]++;
    for(auto e:m){
        s[e.first].push_back(e.second);
        zcnt[e.first]--;
    }
}
ll ans=1;
void solve(){
    cin >> n;
    for(ll i=1;i<=200000;i++){
        zcnt[i] = n;
    }
    for(ll i=1;i<=n;i++){
        scanf("%d", &a[i]);
        primeFac(a[i]);
    }
    for(ll i=2;i<=200000;i++){
        if(zcnt[i]>1)continue;
        sort(s[i].begin(), s[i].end());
        if(zcnt[i]==1) ans*=pow(i, s[i][0]);
        else ans *= pow(i, s[i][1]);
    }
    cout << ans << "\n";
}
int main(){
    solve();
    return 0;
}