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
typedef long long ll;
using namespace std;
const int MM = 1e6+2;
int N, a[MM], mx=INT_MAX, num[MM], sign[MM], ans;
    int M=0;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);
        M += a[i];
    }
    mx = min(a[0], a[1]);
    sign[0]=1;num[0]=0;
    for(int i=1;i<N;i++){
        sign[i] = -1*sign[i-1];
        num[i] = a[i]-num[i-1];if(sign[i]==-1)mx = min(mx, num[i]);else mx = min(mx, min(a[i]-num[i], a[(i+1)%N]-num[i]));

    }
    if(N%2){
        if(a[0]-num[N-1]<0||(a[0]-num[N-1])%2==1){cout << "NO\n"; return 0;}
        ans = (a[0]-num[N-1])/2;
    }
    else{
        ans=mx;
    }
        for(int i=0;i<N;i++){
            if(sign[i]*ans+num[i]<0){printf("NO\n"); return 0;}
            if(sign[i]*ans+num[i]+sign[(i+1)%N]*ans+num[(i+1)%N]!=a[(i+1)%N]){printf("NO\n"); return 0;}

        }

    printf("YES\n"); cout << M/2 << "\n";
        for(int i=0;i<N;i++){
            int cnt=0;
            while(cnt<sign[i]*ans+num[i]){
            printf("%d %d\n", i, (i+1)%N);cnt++;}
        }


    return 0;


}