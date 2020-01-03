#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
long M, Q, dp[105], st[9][105]; 
string s[105];
int rmq(int x, int y){
    if(x>y) return 0;
    int k=log2(y-x+1);
    return max(st[k][x], st[k][y-(1<<k)+1]);
}
int main(){
    cin >> M >> Q;
    for(int i=1;i<=Q;i++) cin >> s[i] >> st[0][i];
    
    for(int i=1;i<9;i++)
        for(int j=1;j+(1<<i)-1<=Q;j++)
            st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    for(int i=1, j=0;i<=Q;i++){
        int limit = ((i+M-1)/M-1)*M;
        if(j<i-M) j=i-M;
        while(j<limit&&dp[j]+rmq(j+1, i) >= dp[j+1]+rmq(j+2, i)) j++;
        dp[i] = max(dp[i], dp[j] + rmq(j+1, i));
    }
    printf("%d\n", dp[Q]);
    return 0;
}
