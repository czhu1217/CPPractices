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
int N, k, a[3002];
int main(){
    int cntl=0, cntr=0;
    int maxl=0;
    ll sum=0;
    scanf("%d %d", &N, &k);
    for(int i=1;i<=N;i++){
        char c;
        cin >> c;
        if(c=='L'){
            a[i]=-1;
            cntl++;
            maxl=i;
            sum += i-cntl;
        }
        else{
            a[i]=1;
        }
    }
    int mi = maxl-1;
    if(mi>k){
        printf("-1\n");
        return 0;
    }
    if(k>sum){
        printf("-1\n");
        return 0;
    }


}