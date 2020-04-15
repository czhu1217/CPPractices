#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int T, n;
bool a[16][16], temp[16][16];
int check(int x){
    memset(temp, 0, sizeof temp);
    for(int i=1;i<=n;i++){
        if(x&&(1<<i)) temp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){

        }
    }

}
int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%d", &n); int ans = INT_MAX;
        for(int i=0;i<=(1<<n);i++){
            ans = min(ans, check(i));
        }
        if(ans==INT_MAX)ans=-1;
        printf("%d\n", ans);
    }
}