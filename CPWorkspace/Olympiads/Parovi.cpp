#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pi;
int N, dp[1<<20], mod = 1e9;
vector<pi> v;
int gcd(int a, int b){
    if (b == 0) 
        return a; 
    return gcd(b, a % b);
}
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(gcd(i, j)==1) v.push_back({i-1, j-1});
        }
    }    
    dp[0] = 1;
    N--;
    for(pi e:v){
        for(int pre = (1<<N)-1;pre>=0;pre--){
            int msk = ((1<<e.second)-1)-((1<<e.first)-1), cur = msk|pre;
            dp[cur] = (dp[cur]+dp[pre])%mod;
        }
    }
    printf("%d", dp[(1<<N)-1]);
    return 0;

    
}