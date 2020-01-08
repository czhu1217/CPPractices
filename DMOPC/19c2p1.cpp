#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int N, mi=1e6+5, mx=0, a[100005];
double q1, q2, q3;
double mid(int l, int r){
    // printf("%d %d\n", l, r);
    if((r-l+1)%2==1){
        // printf("here\n");
        return a[(l+r)/2];
    }
    else{
        return (double)(a[(l+r)/2]+a[(l+r)/2+1])/2;
    }
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);


    }
    sort(a, a+N);
    mi = a[0];
    mx = a[N-1];

    q1 = mid(0, 0+N/2-1);
    q2 = mid(0, N-1);
    if(N%2==1){
        q3 = mid(N/2+1, N-1);

    }
    else q3 = mid(N/2, N-1);
       printf("%lli %lli %.1lf %.1lf %.1lf\n", a[0], a[N-1], q1, q2, q3);
    return 0;
    
}
