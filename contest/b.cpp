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
int a[100005];
void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int ans=1;
    int cnt=1;
    bool flg=0;
    for(int i=1;i<=n;i++){
        if(i>=a[i]){ans=i+1; continue;}   
    }
    cout << ans << "\n";

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}