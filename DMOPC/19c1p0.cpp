#include <stdio.h>
int mi, mx, n, a;
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        if(i==0){
            mi=a;
            mx=a;
        }
        else{
            if(a<mi)mi=a;
            else if(a>mx)mx=a;
        }
    }
    printf("%d\n", mx-mi);
    return 0;
}