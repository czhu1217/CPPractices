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
int vis[27];
int main(){
    int T; cin >> T;
    for(int t=1;t<=T;t++){
        vector<pair<int, int>> v;
        int a[2005];
        memset(vis, 0, sizeof vis);
        int N; cin >> N;
        int a[2005], cnt[2005][27], cn[27];
        memset(cnt, 0, sizeof cnt);
        for(int i=1;i<=N;i++){
            scanf("%d", &a[i]);
            for(int j=1;j<=26;j++) cnt[i][j] = cnt[i-1][j];
            cnt[i][a[i]]++;

        }
        for(int i=1;i<=N;i++){

        }
       

    }
    return 0;
}