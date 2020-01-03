#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const long long mx = 1e9+2;
long long N, B,  ans, lar = 0;

struct fee{ 
    long long p,  s;
    friend bool operator<(fee &a, fee &b){
        return a.p+a.s<b.p+b.s;
    }
} sum[1002];
int main(){
    scanf("%lld %lld", &N, &B);
    for(int i=0;i<N;i++){
        scanf("%lld %lld", &sum[i].p, &sum[i].s );
    }
    sort(sum, sum+N);
    // for(int i=0;i<N;i++){
    //     printf("%lld %lld\n", sum[i].p, sum[i].s);
    // }
    for(int i=0;i<N;i++){
        if(B-sum[i].s-sum[i].p<0){
            break;
        }
        B -= sum[i].p+sum[i].s;
        if(sum[i].p>lar) lar = sum[i].p;
        ans++;

    }
    // printf("%lld %lld\n", lar, ans);
    if(B==0){
        printf("%lld\n", ans);
        return 0;
    }
    
    else{
        // printf("left %lld\n", B+lar/2);
        if(B+lar/2>=sum[ans].p+sum[ans].s){
            printf("%lld\n", ans+1);
            return 0;
        }
    }
    printf("%lld\n", ans);

    return 0;
}