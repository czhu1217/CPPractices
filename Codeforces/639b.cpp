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
void solve(){
    ll n; cin >> n;
    ll cnt=0;
    if(n==1){cout << 0 << "\n"; return;}
    while(n>0){
        ll d = (-1+sqrt(1+24*n))/6;
        if(d==0)break;
        n = n-(3*d+1)*d/2;
        cnt++;
        if(n<=1){break;}

    }
    cout << cnt << "\n";
}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}