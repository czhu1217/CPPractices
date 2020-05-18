//sushi
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
int a;    int n, cnt[4] = {0, 0, 0, 0}; lb memo[305][305][305];
lb calc(int a, int b, int c){
    if(a==0&&b==0&&c==0)return 0;
    if(memo[a][b][c]>0)return memo[a][b][c];
    memo[a][b][c]=(lb)n/(lb)(a+b+c);
    if(a){
        memo[a][b][c] += (lb)a/(lb)(a+b+c)*calc(a-1, b, c);
    }
    if(b){
        memo[a][b][c] += (lb)b/(lb)(a+c+b)*calc(a+1, b-1, c);
    }
    if(c){
        memo[a][b][c] += (lb)c/(lb)(a+b+c)*calc(a,b+1,c-1);

    }
    return memo[a][b][c];


}
void solve(){
 cin >> n;
 memset(memo, 0, sizeof memo);
    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    lb ans = calc(cnt[1], cnt[2], cnt[3]);
    printf("%.10Lf\n", ans);
}
int main(){
    solve();
    return 0;
}