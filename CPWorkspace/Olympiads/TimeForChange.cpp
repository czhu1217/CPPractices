#include <stdio.h>
#include <algorithm>
using namespace std;
    int M, N, c[11], ar[105];
int main(){
    for(int t = 0;t<5;t++){
        scanf("%d %d", &M, &N);
    for(int i=0;i<N;i++){
        scanf("%d", &c[i]);
    }
    for(int i=0;i<=M;i++){
        ar[i]=0;
    }
    for(int i=0;i<N;i++){

        for(int j=0;j<=M;j++){
            if(j==0){
                ar[c[i]]=1;
            }
            else if(ar[j]>0&&j+c[i]<=M){
                if(ar[j+c[i]]==0) ar[j+c[i]] = ar[j]+1;
                else{
                    ar[j+c[i]] = min(ar[j]+1, ar[j+c[i]]);
                }
            }
            else if(j+c[i]>M) break;

        }
    }
    printf("%d\n", ar[M]);

    }
    return 0;
        
    
    
   


}