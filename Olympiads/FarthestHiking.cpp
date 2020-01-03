#include <stdio.h>
using namespace std;
long long int m, n;
int u,f,d; long long int sum = 0;
char c;

int main(){
    scanf("%lld %lld %d %d %d", &m, &n, &u, &f, &d);
    for(long long int i=1;i<=n;i++){
        scanf(" %c", &c);
        if(c!='f'){
            sum += u+d;
        }
        else{
           sum += 2*f;
        }
        if(sum>m){
            printf("%lld", i-1);
            return 0;
        }

    }
    printf("%lld", n);
    return 0;



}