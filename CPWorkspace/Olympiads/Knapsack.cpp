#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, long long int> pi;
int N, W;
vector<pi> v;
long long int x, y, dp[2][100005];
int main(){
    scanf("%d %d", &N, &W);
    for(int i=0;i<N;i++){
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    for(int i=0;i<=W;i++){
        dp[0][i] = v[0].first <= i ? v[0].second : 0;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j-v[i].first<0){
                dp[i%2][j] = dp[(i%2)^1][j];
            }
            else{
               dp[i%2][j] = max(dp[(i%2)^1][j-v[i].first]+v[i].second, dp[(i%2)^1][j]);
            }
        }
    }
    long long int mx=0;
    for(int i=0;i<=W;i++){

        if(dp[(N-1)%2][i]>mx){
            mx = dp[(N-1)%2][i];
        }
    }
    printf("%lld\n", mx);
    return 0;

}
