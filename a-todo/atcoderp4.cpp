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
vector<int> r, g, b;
int main(){
    ll ans=0;
    int N; cin >> N;
    char c;
    for(int i=1;i<=N;i++){
        scanf(" %c", &c);
        if(c=='R') r.push_back(i);
        else if(c=='G') g.push_back(i);
        else if(c=='B') b.push_back(i);

    }
    for(int x=0;x<r.size();x++){
        for(int y=0;y<g.size();y++){
            for(int z=0;z<b.size();z++){
                int a[3]; a[0]=r[x]; a[1] = g[y]; a[2] = b[z];
                sort(a, a+3);
                if(a[1]-a[0]!=a[2]-a[1])ans++;

            }
        }
    }
    cout << ans << "\n";
    return 0;

}