//my stupid solution with weird state and transition but magically passes
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
const int MM = 150005;
int N, a[MM], b[MM], c[MM];
ll prea[MM], preb[MM], prec[MM], op1[MM], op2[MM], op3[MM], op4[MM], op5[MM], op6[MM];
ll ans = LLONG_MAX;

int main(){
    cin >> N;
    prea[0]=0;preb[0]=0;prec[0]=0;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        prea[i] = prea[i-1]+a[i];
    }
    for(int i=1;i<=N;i++){
        scanf("%d", &b[i]);
        preb[i] = preb[i-1]+b[i];
    }
    for(int i=1;i<=N;i++){
        scanf("%d", &c[i]);
        prec[i] = prec[i-1]+c[i];
    }
    for(int i=1; i<=N-2;){
        int id=0;ll mi=LLONG_MAX;
        for(int j=i+1;j<=N-1;j++){
            ll tot = preb[j]-preb[i]+prec[N]-prec[j];
            if(tot<mi){mi=tot;id=j;}
        }
        for(int k=i;k<id;k++){
            op1[k] = preb[id]-preb[k]+prec[N]-prec[id];
        }
        i = id;
    }
        for(int i=1; i<=N-2;){
        int id;ll mi=LLONG_MAX;
        for(int j=i+1;j<=N-1;j++){
            ll tot = prec[j]-prec[i]+preb[N]-preb[j];
            if(tot<mi){mi=tot;id=j;}
        }
        for(int k=i;k<id;k++){
            op2[k] = prec[id]-prec[k]+preb[N]-preb[id];
        }
        i = id;
    }
            for(int i=1; i<=N-2;){
        int id;ll mi=LLONG_MAX;
        for(int j=i+1;j<=N-1;j++){
            ll tot = prea[j]-prea[i]+prec[N]-prec[j];
            if(tot<mi){mi=tot;id=j;}
        }
        for(int k=i;k<id;k++){
            op3[k] =prea[id]-prea[k]+prec[N]-prec[id];
        }
        i = id;
    }            
    for(int i=1; i<=N-2;){
        int id;ll mi=LLONG_MAX;
        for(int j=i+1;j<=N-1;j++){
            ll tot = prec[j]-prec[i]+prea[N]-prea[j];
            if(tot<mi){mi=tot;id=j;}
        }
        for(int k=i;k<id;k++){
            op4[k] = prec[id]-prec[k]+prea[N]-prea[id];
        }
        i = id;
    }
                for(int i=1; i<=N-2;){
        int id;ll mi=LLONG_MAX;
        for(int j=i+1;j<=N-1;j++){
            ll tot = prea[j]-prea[i]+preb[N]-preb[j];
            if(tot<mi){mi=tot;id=j;}
        }
        for(int k=i;k<id;k++){
            op5[k] = prea[id]-prea[k]+preb[N]-preb[id];
        }
        i = id;
    }            
    for(int i=1; i<=N-2;){
        int id;ll mi=LLONG_MAX;
        for(int j=i+1;j<=N-1;j++){
            ll tot = preb[j]-preb[i]+prea[N]-prea[j];
            if(tot<mi){mi=tot;id=j;}
        }
        for(int k=i;k<id;k++){
            op6[k] = preb[id]-preb[k]+prea[N]-prea[id];
        }
        i = id;
    }

    //a, b, c
    for(int i=1;i<N-1;i++){
        int p = op1[i];
        ans = min(ans,prea[i]+op1[i]);
    }
    //a, c, b;
        for(int i=1;i<N-1;i++){
        ans = min(ans,prea[i]+op2[i]);
    }
    //b, a, c
    for(int i=1;i<N-1;i++){
        ans = min(ans,preb[i]+op3[i]);


    }
    //b, c, a
    for(int i=1;i<N-1;i++){
        ans = min(ans,preb[i]+op4[i]);
    
    }
    //c, a, b
        for(int i=1;i<N-1;i++){

        ans = min(ans,prec[i]+op5[i]);

    }
    //c, b, a
        for(int i=1;i<N-1;i++){
          ans = min(ans,prec[i]+op6[i]);


    }
    cout << ans << "\n";
    return 0;


}