#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int a[MM], N;
double dp[MM], bur[MM], ans=0;
int main(){
    cin >> N ;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
    }
    for(int k=N;k>0;k--){
        if(a[k]==a[1]) dp[k] = 1;
        else if(a[k]==a[N]) dp[k] = 0;
        else if(bur[a[k]]) dp[k] = bur[a[k]];
        else  dp[k] =  (ans+1)/(double)(N-k+1);
        bur[a[k]] = dp[k];
        ans += dp[k];
    }
    ans /= (double)N;
    printf("%.8f\n", ans);
    return 0;
}