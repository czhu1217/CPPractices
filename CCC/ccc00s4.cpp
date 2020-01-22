//golf
#include <stdio.h>
#include <cstring>
using namespace std;
int dis,n, a[33], dp[5282];

int main(){
    scanf("%d %d", &dis, &n);
    memset(dp, 0x3f, sizeof(dp));
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        for(int j=1;j<=n;j++){
            if(j-a[i]>=0){
               dp[j]++; 
            }

        }
    }
    
}