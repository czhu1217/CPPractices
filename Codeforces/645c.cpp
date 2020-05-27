//https://codeforces.com/contest/1358/problem/C
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
    ll ans=0;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
   cout << (x2-x1)*(y2-y1)+1 << "\n";

}
int main(){
    ll t; cin >> t;
    while(t--)solve();
    return 0;
}