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
const int MM = 1e5+5;
int T, N, a[100005], x[MM], y[MM], z[MM], b[MM];
int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        bool flg=true;
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        memset(z, 0, sizeof z);

        scanf("%d", &N);
        for(int i=1;i<=N;i++){
            scanf("%d", &a[i]);
            x[i] = x[i-1]; y[i]=y[i-1];z[i]=z[i-1];
            if(a[i]==1) x[i]++;
            else if(a[i]==0)y[i]++;
            else z[i]++;
        }
        for(int i=1;i<=N;i++) scanf("%d", &b[i]);
        for(int i=1;i<=N;i++){
            int dif = b[i]-a[i];
            if(dif==0)continue;
            if(dif>0){
                if(x[i-1]>0) continue;
                else{
                    flg=false; break;
                }
            }
            else if(dif<0){
                if(z[i-1]>0)continue;
                else{
                    flg=false;
                    break;
                }

            }

        }
        if(flg)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}