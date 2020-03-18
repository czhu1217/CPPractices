#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <deque>
#include <unordered_map>
typedef long long ll;
using namespace std;
#define f first
#define s second
const int MM = 1e5+2;
ll n, k, a[MM*2], pre[MM*2];
ll ans=0, cnt = 0, sum=0, last=0;
deque<pair<ll, ll>> mi;
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=k;i++){
        a[i+n] = a[i];
    }
    pre[0] = 0;
    for(int i=1;i<=n+k;i++){
        pre[i] = pre[i-1]+a[i];
    }
    for(int i=1;i<=n+k;i++){
        if(i>k){
            while(!mi.empty()&&mi.front().first<i-k){
                mi.pop_front();
            }
        }
        while(!mi.empty()&&mi.back().second>pre[i]){
            mi.pop_back();
        }
        mi.push_back({i, pre[i]});
        ans = max(ans, pre[i]-mi.front().second);
        
    }
    cout << ans << "\n";
    return 0;


}
