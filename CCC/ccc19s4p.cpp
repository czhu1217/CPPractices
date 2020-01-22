#include<iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
ll dp[MM], t1[MM], t2[MM]; int a[MM], N, K, pmx[MM], smx[MM], day[MM];
int main(){
    scanf("%d %d", &N, &K);
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        day[i] = (i+K-1)/K;
        if(day[i]!=day[i-1]){
            pmx[i] = a[i];
        }
        else pmx[i] = max(a[i], pmx[i-1]);

    }
    for(int i=N;i>=1;i--){
        if(day[i] != day[i+1]) smx[i] = a[i];
        else smx[i] = max(smx[i+1], a[i]);
    }
    for(int i=1;i<=K;i++) dp[i] = pmx[i];
    for(int i=2;i<=day[N];i++){
        int l = (i-2)*K+1, r = (i-1)*K;
        for(int j=r; j>=l;j--){
            t1[j] = dp[j] + (j==r?0:smx[j+1]);
            t2[j] = dp[j];
            if (j!=r){
                t1[j] = max(t1[j+1], t1[j]);
                t2[j] = max(t2[j+1], t2[j]);
            }


        }
        for(int j=r+1;j<=min(i*K, N); j++){
            dp[j] = max(t1[j-K], t2[j-K]+pmx[j]);
        }
    }
    cout << dp[N] << "\n";
}