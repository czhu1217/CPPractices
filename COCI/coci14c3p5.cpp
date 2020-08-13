//stogovi
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 3e5+2, MM2 = 20;
int n, v; char op; int w, val[MM], dis[MM];
int st[MM2][MM*2+1];
int lca(int u, int v){
    if(dis[u]>dis[v])swap(u, v);
    for(int j=MM2-1;j>=0;j--){
        if(dis[v]-dis[u]>=(1<<j)){
            v = st[j][v];
        }
    }
    if(u==v)return v;
    for(int j=MM2-1;j>=0;j--){
        if(st[j][u]!=st[j][v]){
            u = st[j][u];
            v = st[j][v];
        }
    }
    return st[0][u];
}
int main(){cin.sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    st[0][0]=-1; dis[0]=0;val[0]=0;
    for(int i=1;i<=n;i++){
        cin >> op >> v;
        v = val[v];
        if(op=='a'){
            val[i]=i;
            dis[i]=dis[v]+1;
            st[0][i]=v;
            for(int j=1;j<MM2;j++){
                if(st[j-1][i]!=-1) st[j][i] = st[j-1][st[j-1][i]];
            }

        }
        if(op=='b'){
            cout << v << "\n";
            val[i] = st[0][v];
        }
        if(op=='c'){
            int w; cin >> w;
            w = val[w];
            val[i]=v;
            cout << dis[lca(v, w)] << "\n";
        }
    }
    return 0;
}
