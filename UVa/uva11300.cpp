/* Spreading the Wealth
equation rearrangments
shortest distance sum from a point to every point on a line is the mid point
*/
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
int N, a[10000002], c[10000002];
ll sum=0, M, ans=0;
int main(){
    while(scanf("%d", &N)==1){
        sum=0;
        ans=0;
        for(int i=1;i<=N;i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        M = sum/N;
        c[0]=0;
        for(int i=1;i<N;i++){
            c[i] = c[i-1]+a[i]-M;
        }
        sort(c, c+N);
        int mid = c[N/2];
        for(int i=0;i<N;i++){
            ans += abs(mid-c[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;

}