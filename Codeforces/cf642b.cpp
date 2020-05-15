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
void solve(){
    int n, k; cin >> n >> k;
    int a[31], b[31];
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &b[i]);
    }
    sort(a+1, a+1+n);
    sort(b+1, b+n+1);
    reverse(b+1, b+n+1);
    for(int i=1;i<=k;i++){
        if(a[i]<b[i]){
            a[i]=b[i];
        }
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum += a[i];
    }
    cout << sum << "\n";

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}