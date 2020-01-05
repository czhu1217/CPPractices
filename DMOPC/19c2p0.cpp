//roller coaster
#include <stdio.h>
int N, mx, mi,  cnt;
int main(){
    scanf("%d %d %d", &N, &mi, &mx) ;
    cnt = N;
    for(int i=0;i<N;i++){
        int t;
        scanf("%d", &t);
        if(t<mi||t>mx) cnt--;

    }
    printf("%d\n", cnt);
    return 0;
}