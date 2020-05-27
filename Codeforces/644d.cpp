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
    vector<int> v;
    int mx=0;
    int n, k; cin >> n >> k;
    if(k>=n){
        cout << 1 << "\n"; return;
    }
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            v.push_back(i); v.push_back(n/i);
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]<=k&&v[i]>mx){
            mx = v[i];
        }
    }
    cout << n/mx << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}