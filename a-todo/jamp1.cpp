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
int T, N, a[102][102];

ll trace;

int main(){
    cin >> T;
    for(int x=1;x<=T;x++){
        int cntr=0, cntc=0;
        trace = 0;
        cin >> N;
        int m[1002];
        set<int> r[102], c[102];

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                cin >> a[i][j];
                m[a[i][j]]++;

            }
        }
        for(int i=1;i<=N;i++){
            trace += a[i][i];
        }
        for(int i=1;i<=N;i++){
            bool cnt[102];
            memset(cnt, 0, sizeof(cnt));
            for(int j=1;j<=N;j++){
                if(cnt[a[i][j]]){
                    cntr++;
                    break;
                } 
                else cnt[a[i][j]] = true;
            }
        }
        for(int j=1;j<=N;j++){
            bool cnt[102];
            memset(cnt, 0, sizeof(cnt));
            for(int i=1;i<=N;i++){
                if(cnt[a[i][j]]){
                    cntc++;
                    break;
                } 
                else cnt[a[i][j]] = true;
            }
        }
        
        printf("Case #%d: %lld %d %d\n", x, trace, cntr, cntc);
    
    }
    return 0;

}