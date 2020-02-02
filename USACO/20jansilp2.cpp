#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
long long N, K, M, x, ans;
bool check(long long mid){
    long long tot = 0, days = 0;
    while(days<K&&tot<N){
        long long y = (N-tot)/mid;
        if(y<=M) return tot + (K-days)*M;
        long long temp = min(K-days, (N-mid*y)/y+1);
        tot += temp*y;
        days += temp;
    }
}
int main(){
    cin >> N >> K >> M;
    int lo = 1, hi = N;
    while(lo<=hi){
        long long mid = (lo+hi)/2;
        if(check(mid)>N){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans << "\n";


}