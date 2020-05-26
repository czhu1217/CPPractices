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
using namespace std;
typedef long long ll;
int a[1005], ans = INT_MAX;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n, t; cin >> n >> t;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    for(int i=1;i+t-1<=n;i++){
        int lm = a[i], rm = a[i+t-1];
        if(lm<0&&rm>0){
            int temp = min(abs(lm)*2+rm, abs(lm)+rm*2);
            ans = min(ans, temp);
        }
        else if(rm<0) ans = min(ans, abs(lm));
        else ans = min(ans, rm); 
    }
    cout << ans << "\n";
    return 0;
}