#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
// typedef pair<int, long long int> pi;
int N, W;
// vector<pi> v;
 int x, y, dp[100005], ans, mx=1e5+2;
int main(){
    scanf("%d %d", &N, &W);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i=1, w, v;i<=N;i++){
        scanf("%d %d", &w, &v);
        for(int j=mx;j>=v;j--){
            dp[j] = min(dp[j], dp[j-v]+w);

        }
    }
 
    for(int i=mx;i>=0;i--){
        if(dp[i] <= W){
            printf("%d\n", i);
            break;
        }
    }
    

    return 0;

}
