#include <stdio.h>
using namespace std;
long long int N, num;
int main(){
    scanf("%lld", &N);
    for(int i=0;i<N;i++){
        scanf("%lld", &num);
        if((num&(num-1))==0){
            printf("T\n");
        }
        else{
            printf("F\n");
        }
    }
    return 0;
}