#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
ll N;
ll dp[10000000];
ll recur(ll n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n<10000000&&dp[n]){
        return dp[n];
    } 
    ll t = sqrt(n);
    ll value = 0;
    for(int i=2;i<=t;i++){
        value += recur(n/i) + (n/(i-1)-n/i)*recur(i-1);
    }
    value += (n/t-t)*recur(t);
    if(n<10000000) dp[n] = value;
    return value;
}
int main(){
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    cout << recur(N);
    return 0;
}