#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N;
bool dp[402][402];
ll ans = 0, memo[402][402], l, r;
bool work(int a, int b){
    int i=0, j=0, aa = a, bb = b;
    l = memo[aa][aa]; r = memo[bb][bb];
    while(true){
        if(a >= b) return false;
        if(l == r && (b-a==1||(dp[a+1][b-1]))){
            memo[aa][bb] = l + r + memo[a+1][b-1];
            if(memo[aa][bb]>ans) ans = memo[aa][bb];
            return true;
        }
        if(l<r){
            for(j = a+1; j < b ;j++){
                if(dp[aa][j]){
                    l = memo[aa][j];
                    a = j;
                    break;
                }
            }
            if(j==b) return false;
        }
        else{
            for( i=b-1; i>a;i--){
                if(dp[i][bb]){
                    r = memo[i][bb];
                    b = i;
                    break;
                }
            }
            if(i==a) return false;
        }
    }
}

int main(){
    cin >> N;
    memset(dp, false, sizeof(dp));
    memset(memo, 0, sizeof(memo));
    for(int i=1;i<=N;i++){
        cin >> memo[i][i];
        if(memo[i][i]>ans) ans = memo[i][i];
        dp[i][i] = true;
    }
    for(int i=1;i<=N-1;i++){
        for(int j=1;j<=N-i+1;j++){
            if(work(j, j+i)){
                dp[j][j+i] = true;
            }
        }
    }
    cout << ans << "\n";
    return 0;

}