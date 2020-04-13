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
int cnt[200005]; bool vis[200005];
int main(){
    int T; cin >> T;
    for(int t=1;t<=T;t++){
        int uniq=0, mx=1, id;
        memset(vis, 0, sizeof vis);
        memset(cnt, 0, sizeof cnt);
        int N; cin >> N;
        for(int i=1, x;i<=N;i++){
            scanf("%d", &x);
            if(!vis[x]){
                vis[x] = true;
                cnt[x]=1;
                uniq++;
            }
            else{
                cnt[x]++;
                if(mx<cnt[x]){mx=cnt[x]; id=x;}
            }
        }
        if(mx>uniq){
            printf("%d\n", uniq);
        }
        else if(mx==uniq){
            printf("%d\n", uniq-1);
        }
        else{
            printf("%d\n", mx);
        }

    }
    return 0;
}