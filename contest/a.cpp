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
    int n, m, k;cin >> n >> m >> k;
    int get = min(m, n/k);
    int rem = m - get;
    if(get==1&&rem) cout << 0 << "\n";
    else{
        int mi = ceil((double)rem/(double)(k-1));
    cout << get-mi << "\n";

    }

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}