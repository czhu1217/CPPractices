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
    int n, m; cin >> n >> m;

    if(n==1||m==1){cout << "YES\n" ; return;}
    if(n==2&&m==2){cout << "YES" << "\n"; return;}
    else cout << "NO" << "\n"; 

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}