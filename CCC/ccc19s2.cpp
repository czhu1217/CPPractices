#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int t, n;
bool prime(int x){
    int rt = sqrt(x)+1;
    for(int i=2;i<=rt;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    scanf("%d", &t);
    for(int k=0;k<t;k++){
        scanf("%d", &n);
        int nn = 2*n;
        for(int i=2;i<=n;i++){
            int j = nn-i;
            if(prime(i)&&prime(j)){
                printf("%d %d\n", i, j);
                break;
            }
        }

    }
    return 0;
}