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
using namespace std;
typedef long long ll;
int N, a[200005];
ll pre[200005]; bool dp[200005], dis[200005];
int main(){
    ll cnt=0;
    scanf("%d", &N);
    pre[0]=0;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        pre[i] = a[i]+pre[i-1];
    }
    for(int i=1;i<=N;i++){
        if(a[i]){
            dp[i]=1;
            cnt++;
        } 
        else dp[i]=0;
    }
    int lim=N;
    for(int i=1;i<=N;i++){
        
    }
    printf("%d\n", cnt);
    return 0;
 
}