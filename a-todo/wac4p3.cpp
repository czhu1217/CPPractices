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
#include <climits>
#include <limits.h>
#include <float.h>
#define LSOne(S) ((S) & -(S))
using namespace std;
typedef long long ll;
const int MM = 20;
int N, S;
struct sq{
    int sx, sy, vx, vy;
} ar[16]; 
double ans = INT_MAX;
double memo[MM][1<<(MM)], dist[MM];
double tsp(int u, int mask){
    double ans = DBL_MAX;
    if(mask==0)return dist[u];
    if(memo[u][mask]!=DBL_MAX)return memo[u][mask];
    for(int i=1;(1<<(i-1))<=mask;i++){
        if(!(mask&(1<<i-1)))continue;
        double prev = tsp(i, mask^(1<<(u-1)));
        double x1, x2, y1, y2, dx, dy;
        x1=ar[i].sx+prev*ar[i].vx; y1=ar[i].sy+prev*ar[i].vy;
        x2=ar[u].sx+prev*ar[u].vx; y2=ar[u].sy+prev*ar[u].vy;
        dx = x2-x1; dy=y2-y1;
        double a, b, c;
        a = (ar[u].vx*ar[u].vx+ar[u].vy*ar[u].vy-S*S); b=2*(dx*ar[u].vx+dy*ar[u].vy); c=dx*dx+dy*dy;
        double time =max((-1*b+sqrt(b*b-4*a*c))/(2*a), (-1*b-sqrt(b*b-4*a*c))/(2*a));
        ans = min(ans, time);

    }
    memo[u][mask]=ans;return ans;
}
int main(){
    cin >> N >> S;
    ar[0].sx=0; ar[0].sy=0; ar[0].vy=0; ar[0].vx=0;
    for(int i=1, a, b, c, d;i<=N;i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ar[i] = {a, b, c, d};
    }
    for(int i=1;i<=N;i++){
        double sx = ar[i].sx, sy=ar[i].sy,vx=ar[i].vx,vy=ar[i].vy;
        double a, b, c;
        a = (vx*vx+vy*vy-S*S); b=2*(sx*vx+sy*vy); c=sx*sx+sy*sy;
        dist[i] = max((-1*b+sqrt(b*b-4*a*c))/(2*a), (-1*b-sqrt(b*b-4*a*c))/(2*a));
    }
    for(int i=0;i<20;i++)
{
    for(int j=0;j<1048576;j++){
        memo[i][j] = DBL_MAX;
    }
}   for(int i=1;i<=N;i++){
    ans = min(ans, tsp(i, ((1<<N)-1)^(1<<(i-1))));

}
    cout << ans << "\n";

    return 0;
    
    


}