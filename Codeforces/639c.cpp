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
const int MM = 2e5+5;
void solve(){
    int n; ll a[MM]; int rm[MM];
    memset(rm, 0, sizeof rm);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int mod = ((i+a[i])%n+n)%n;
        rm[mod]++;
        if(rm[mod]>1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}