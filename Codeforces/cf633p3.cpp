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
int main(){
    int T; scanf("%d", &T);
    for(int t=1;t<=T;t++){
        ll mx=LLONG_MIN;
        int N; scanf("%d", &N); ll cnt=0;
        ll  dif[100005]; 
        for(int i=1, x;i<=N;i++){
            scanf("%d", &x);
            if(x>mx)mx=x;
            dif[i] = mx-x;
        }
        for(int i=0;i<=40;i++){
            for(int j=1;j<=N;j++){
                if((dif[j]>>i)&1){
                    cnt=i+1;break;
                }
            }
        }        
        printf("%lld\n", cnt);
        
    }
    return 0;
}
 