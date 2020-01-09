#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m; long long a[502][502], cntr, cntc; long long cost[502][502],mi;

int main(){
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof(a));
    cntr = n;
    cntc = m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld", &a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        a[i][1] += a[i-1][1];
    }
    for(int i=1;i<=m;i++){
        a[1][i] += a[1][i-1];
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            a[i][j] += min(a[i-1][j], a[i][j-1]);
        }
    }
    printf("%lld\n", a[n][m]);
    return 0;

    }
