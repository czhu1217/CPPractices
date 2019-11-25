#include <stdio.h>
using namespace std;
int main(){
    int n;
    long long int k = 0, t;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &t);
        k = k^t;
    }
    printf("%lld\n", k);
    return 0;
}