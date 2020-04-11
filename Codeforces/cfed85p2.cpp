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
int a[100005]; ll pre[100005];
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n,x; ll sum=0;
        scanf("%d %d", &n, &x);
        memset(a, 0, sizeof a);
        memset(pre, 0, sizeof pre);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int mx = sum/x;
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i] = a[i]+pre[i-1];
        }
        int i=mx;
        for(i=min(mx, n);i>0;i--){
            if(pre[i]/i>=x){
                break;
            }
        }
        printf("%d\n", i);
    }
    return 0;


}