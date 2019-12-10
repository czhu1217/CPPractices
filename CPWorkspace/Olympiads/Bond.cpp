//bitmask dp
#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
double p[22][22], dp[1<<20];
int N;
double fun(int bond, int mask){
    if(dp[mask]>=0) return dp[mask];
    if(bond>=N) return 1;
    double ret = 0.0;
    for(int k=0;k<N;k++){
        if(!(mask&(1<<k))){
        ret = max(ret, p[bond][k]*fun(bond+1, mask|(1<<k)));
        } 
    }
    return dp[mask] = ret;
}
int main(){
    cin >> N;
    fill(dp, dp+(1<<20), -1.0); //fills every element as -1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> p[i][j];p[i][j] /= 100.0;
        }

    }
    printf("%.6f\n", fun(0, 0)*100.0);
}