#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int N, M, Q, v, req, pre; long long ans = 0;
int dis[1000002], a[1000002];
int main(){
    scanf("%d %d %d", &N, &M, &Q);
    for(int i=0;i<Q;i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+Q);
    for(int i=0;i<Q-1;i++){
        dis[i] = a[i+1] - a[i] - 1;
    } 
    sort(dis, dis+Q-1);
    int req = Q-M;
    for(int i=0;i<req;i++){
        ans += dis[i];
    }
    printf("%lld\n", ans+Q);
    
    return 0;
    
    
  


}