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
    ll a, k; ll ans=a;
    cin >> a >> k; ans=a;
    for(int i=1;i<k;i++){
        int mi=9,mx=0;
        while(a>0){
            if(a%10>mx)mx=a%10;
            if(a%10<mi)mi=a%10;
            a/=10;

        }
        ans += mi*mx;
        a = ans;
        if(mi==0){
            cout << ans << "\n";
            return;
        }
    }
    cout << ans << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}