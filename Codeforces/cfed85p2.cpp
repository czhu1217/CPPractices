#include <iostream>
#include <stdio.h>
#include <cstring>
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
ll a[100005]; ll pre[100005];
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n,x; ll sum=0;
        scanf("%d %d", &n, &x);
        memset(a, 0, sizeof a);
        memset(pre, 0, sizeof pre);
        for(int i=1;i<=n;i++){
            scanf("%lld", &a[i]);
        }
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i] = a[i]+pre[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            sum += a[i];
            if(sum>=(ll)x*i) ans=i;
        }
        printf("%d\n", ans);
    }
    return 0;


}