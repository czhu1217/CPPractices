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
#include <fstream>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int N, ans = 1, lol[100005], hir[100005];
struct pi{
    int f, s;
    bool operator<(const pi &e){
        return e.f==f?s<e.s:f<e.f;
    }
} co[MM];
int main(){
    cin >> N;
    for(int i=1, x, y;i<=N;i++){
        scanf("%d %d", &x, &y);
        co[i] = {x, y};
    }
    sort(co+1, co+N+1);
    lol[1]=co[1].s;
    for(int i=2;i<=N;i++) lol[i] = min(co[i].s, lol[i-1]);
    hir[N]=co[N].s;
    for(int i=N-1;i>0;i--) hir[i] = max(co[i].s, hir[i+1]);
    for(int i=1;i<N;i++) if(lol[i]>hir[i+1]) ans++;
    cout << ans << "\n";
    return 0;
}