#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, t, a[3002][3002], cur, nxt;
long long ans;
int main(){
    scanf("%d %d", &n, &k );
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int m=1;m<k; m += max(1, m/2)){
        int d = max(1, m/2);
        for(int i=1;i<=n-m + max(1, m/2)+1;i++){
            for(int j=1;j<=i;j++){
                a[i][j] = max(a[i][j], max(a[i+d][j],a[i+d][j+d]));

            }
        }
        if(k-m<m/2){
            d = k-m;
            for(int i=1;i<=n-m + max(1, m/2)+1;i++){
            for(int j=1;j<=i;j++){
                a[i][j] = max(a[i][j], max(a[i+d][j],a[i+d][j+d]));

            }
            
        }
        break;
        }
    }
    for(int i=1;i<=n-k+1;i++)
        for(int j=1;j<=i;j++)
            ans+= a[i][j];
    printf("%lld\n", ans);
    return 0;
}

