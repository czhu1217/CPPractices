#include <stdio.h>
int N;
char a[1005], ans[1005];
int main(){
    scanf("%d", &N);
    scanf(" %c", &a[0]);
    for(int i=1;i<N;i++){
        scanf(" %c", &a[i]);
        if(a[i-1]==a[i]){
            ans[i-1] = '0';
        }
        else{
            ans[i-1] = '1';
        }
    }
    if(a[N-1]=='1') ans[N-1]='1';
    else ans[N-1]='0';
  
    for(int i=0;i<N;i++){
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;

}