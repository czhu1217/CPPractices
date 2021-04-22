#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
const int MM = 1e6+4;
int n, a[MM]; int dp[MM];
int sum3(int a, int b, int c){
    if(a>b)swap(a, b);
    if(a>c)swap(a, c);
    return a*0.5+b+c;
    
}
    int main(){
    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i];
    dp[1] = a[1];
    dp[2] = min(a[1], a[2])*0.75 + max(a[1], a[2]);
    for(int i=3;i<=n;i++){
        int c1, c2, c3;
        c1 = dp[i-1]+a[i];
        c2 = dp[i-2]+min(a[i], a[i-1])*0.75+max(a[i], a[i-1]);
        c3 = dp[i-3] + sum3(a[i], a[i-1], a[i-2]);
        dp[i] = min(c1, min(c2, c3));
    }
    cout << dp[n] << "\n";
    return 0;
}