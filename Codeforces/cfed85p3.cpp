#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;
typedef long long ll;
pair<ll, ll> a[300005];ll sum=0;
ll ans = LLONG_MAX;
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        sum=0;
        ans=LLONG_MAX;
        ll mx = 0;
        int N; scanf("%d", &N);
        for(int i=1;i<=N;i++){
            scanf("%lld %lld", &a[i].first, &a[i].second);
            if(i>1) sum += max((ll)0, a[i].first-a[i-1].second);
        }
        sum += max((ll)0, a[1].first-a[N].second);
        ans = min(ans, a[1].first+sum-max((ll)0, a[1].first-a[N].second));
        for(int i=2;i<=N;i++){
                ans = min(ans, sum-max((ll)0, a[i].first-a[i-1].second)+a[i].first);
        } 
        printf("%lld\n", ans); 
    }
    return 0;
 
}