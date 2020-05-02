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
using namespace std;
typedef long long ll;
ll ans;
void solve(){
    ans=-1;
    int x, y; cin >> x >> y;
    string M; cin >> M;
    for(int i=0;i<M.size();i++){
        if(M[i]=='N'){
            y++;
        }
        else if(M[i]=='S') y--;
        else if(M[i]=='E')x++;
        else if(M[i]=='W')x--;
        if(abs(x)+abs(y)<=i+1){
            ans = i+1;
            return;
        }


    }
}
int main(){
    int T; cin >> T;
    for(int t=1;t<=T;t++){
        printf("Case #%d: ", t);
        solve();
        if(ans==-1)printf("IMPOSSIBLE\n");
        else printf("%lld\n", ans);



    }
    return 0;
}