#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int V, N, c[2001], dp[10001], ans[100001];
const int mx = 10001;
struct q{
    int p, c, l;
    bool operator<(q &a){ 
        return l<a.l;
    }
} qu[100001];
int main()
{
    cin >> N >> V;

    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }
    for(int i=0;i<V;i++){
        qu[i].p = i;
        cin >> qu[i].c >> qu[i].l;
        }
    sort(qu, qu+V);
   
    
    memset(dp, 0x3f, sizeof(dp));
    int cnt = 0;
    dp[0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=c[i]; j<mx;j++){
            dp[j] = min(dp[j], dp[j-c[i]]+1);
        }

        while(cnt<V&&qu[cnt].l==i){
            if(dp[qu[cnt].c]!=0x3f3f3f3f) ans[qu[cnt].p] = dp[qu[cnt].c];
            else ans[qu[cnt].p] = -1;
            cnt++;

        }
    }
    for(int i=0;i<V;i++){
        cout << ans[i] << endl;
    }
    return 0;
}