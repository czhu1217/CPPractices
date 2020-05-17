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
const int MM = 2e5+2;
int a[MM];
void solve(){
    int n; cin >> n;

    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    ll ans=0;
    int cur=0, mx;
    for(int i=1;i<=n;i++){
            cur++;
            if(cur==1){
                mx = a[i];
            }
            else{
                mx = max(mx, a[i]);
            }
        if(cur>=mx){ans++;cur=0;}



    }
    cout << ans << "\n";

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}