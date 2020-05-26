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
ll binomialCoeff(ll n, ll k) 
{ 
    ll C[100005]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
void solve(){
    ll ans=0;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll dx = x2-x1, dy = y2-y1;
    ll n = dx+dy, k = min(dx, dy);
    
    cout << binomialCoeff(n, k) << "\n";
}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}