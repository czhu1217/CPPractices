#include <stdio.h>
using namespace std;
int x, y, h, v, t;
int main(){
    scanf("%d %d %d %d", &x, &y, &h, &v);
    scanf("%d", &t);
    int minht = x/2;
    int minvt = y/2;
    if(!(minht<t&&minvt<t)){
        printf("%s", "NO");
        return 0;
    }
    for(int i=x/2;i+x-2*i<t;i--){
        int step = x-2*i;
        if(i+step*2<=y+v&&i+step*2>=y){
            printf("%s", "YES");
            return 0;
        }
    }
    for(int i=y/2;i+y-2*i<t;i--){
        int step = y-2*i;
        if(i+step*2<=x+h&&i+step*2>=x){
            printf("%s", "YES");
            return 0;
        }
    }
    printf("%s", "NO");
    return 0;

}