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
using namespace std;
typedef long long ll;
int N, S;
struct sq{
    int sx, sy, vx, vy;
} ar[16];  bool vis[16];
double ans = 0;
double rmx=0, lmx=0, rd=0, ld=0, rs=0, ls=0;
int main(){
    cin >> N >> S;
    for(int i=1, a, b, c, d;i<=N;i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ar[i] = {a, b, c, d};
        if(a>0){
            if((double)a/(double)(S-c)>rmx){
                rmx = (double)a/(double)(S-c);
                rd=a; rs=c;
            }
        }
        if(a<0){
            if((double)-1*a/(double)(S+c)>lmx){
            lmx = (double)-1*a/(double)(S+c);
            ld=a; ls=c;
            }

        }
    }
    if(rmx>lmx){
        ans += rmx;
        ans += (rmx*S-rmx*ls+ld)/(S+ls);
    }
    else{
        ans += lmx;
        ans += (lmx*S+lmx*rs+rd)/(S-rs);
    }
    cout << ans << "\n";

    return 0;
    
    


}