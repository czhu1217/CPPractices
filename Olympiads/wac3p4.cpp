#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
ll N, K, M, x, ans, lo, hi;
ll check(ll mid){
    ll tot = 0, days = 0;
    while(days<K && tot<N){
        ll y = (N-tot)/mid;
        if(y<=M) return tot + (K-days)*M;
        ll temp = min(K-days, (N-mid*y-tot) / y + 1);
        tot += temp*y;
        days += temp;
    }
    return tot;
}
int main(){
    cin >> N >> K >> M;
    lo = 1, hi = N;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(check(mid)>=N){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    cout << ans << "\n";
    return 0;


}