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
int a[1000006];
void solve(){
    int n, s; cin >> n >> s;
    if(s<n*2){cout << "NO" << "\n"; return;}
    cout << "YES" << "\n";
    for(int i=1;i<n;i++) cout << 2 << " ";
    cout << s-2*(n-1) << "\n";
    cout << 1 << "\n";
    



}
int main(){
    solve();
    return 0;
}