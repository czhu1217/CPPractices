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
#define LSOne(S) ((S) & -(S))
using namespace std;
typedef long long ll;
const int MM = 16;
int N, S;
struct sq{
    int sx, sy, vx, vy;
} ar[16]; 
long double ans;
long double memo[MM][1<<(MM-1)], dist[MM];
long double tsp(int u, int mask){
    if(mask==0)return dist[u];
    long double &ans=memo[u][mask];
    if(ans>=0)return ans;
    ans = 1e15;
    int m = mask;
    for(int i=1;(1<<(i-1))<=m;i++){
        if((m&(1<<(i-1)))==0)continue;
        int v = i;
        long double prev = tsp(v, m^(1<<(i-1)));
        if(u==0){ans = min(ans, prev); continue;}
        long double xii = ar[u].sx+ar[u].vx*prev, yii = ar[u].sy+ar[u].vy*prev;
        long double xi= ar[v].sx+ar[v].vx*prev, yi = ar[v].sy+ar[v].vy*prev;
        long double dx=xii-xi, dy=yii-yi;
        long double vx = ar[u].vx, vy = ar[u].vy;
        long double a, b, c;
        a = (vx*vx+vy*vy-S*S); b=2*(dx*vx+dy*vy); c=dx*dx+dy*dy;
        long double dist = max((-1*b+sqrt(b*b-4*a*c))/(2*a), (-1*b-sqrt(b*b-4*a*c))/(2*a));
        ans = min(ans, dist+prev);
    }
    return ans;
}
int main(){
    cin >> N >> S;
    for(int i=1, a, b, c, d;i<=N;i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ar[i] = {a, b, c, d};
    }
    for(int i=1;i<=N;i++){
        long double sx = ar[i].sx, sy=ar[i].sy,vx=ar[i].vx,vy=ar[i].vy;
        long double a, b, c;
        a = (vx*vx+vy*vy-S*S); b=2*(sx*vx+sy*vy); c=sx*sx+sy*sy;
        dist[i] = max((-1*b+sqrt(b*b-4*a*c))/(2*a), (-1*b-sqrt(b*b-4*a*c))/(2*a));
    }
    memset(memo, -1, sizeof(memo));
    ans = tsp(0, (1<<(N))-1);
    cout << ans << "\n";

    return 0;
    
    


}