#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int  N, Q, l, r,p[100005];
long long int d[100005];

long long int sum;
int main(){
    scanf("%d %d", &N, &Q);
    d[0] = 0;
    p[0] = 0;

    for(int i=1;i<=N;i++){
        scanf("%d ", &p[i]);
    }
    sort(p, p+N+1);
    for(int i=0;i<=N;i++){
        d[i] = 0;
    }
    for(int i=0;i<Q;i++){
        scanf("%d %d", &l, &r);
        d[l]++;
        d[r+1]--;
    }
    for(int i=1;i<=N;i++){
        d[i] = d[i-1] + d[i];
    }
    sort(d, d+N+1);
    for(int i=1;i<=N;i++){
        sum += d[i]*p[N+1-i];
    }
    printf("%lld\n", sum);
    return 0;

}