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
int T;
int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int cnt=0;
        printf("Case #%d: \n", t);
        int N;
        scanf("%d", &N);
        bool tog=true;
        int i=1;
        for(i=1;i<=N;i++){
            if(N<pow(2, i-1))break;
            if(tog){
                for(int j=1;j<=i;j++){
                    printf("%d %d\n", i, j);
                }
                tog = !tog;
            }
            else{
                for(int j=i;j>=1;j--){
                    printf("%d %d\n", i, j);
                }
                tog=!tog;
            }
            N -= pow(2, i-1);
        }
        while(N>0){
            if(tog){
                if(N>i-1){
                    N-=i-1;
                    printf("%d %d\n" ,i, 2);
                }
                else{
                    N--;
                    printf("%d %d\n", i, 1);
                }
            }
            else{
                if(N>i-1){
                    N-=i-1;
                    printf("%d %d\n", i, i-1);
                }
                else{
                    N--;
                    printf("%d %d\n", i,i);
                }

            }
            i++;
        }

    }
    return 0;
}
