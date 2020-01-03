//simple implementation that just tests on "struct"...
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long int lld;


int S, N, Q, lo= 0, hi, mid;
struct beb{ 
    lld u,b, d, c;
    friend bool operator<(beb &x, beb &y)
    {
        if(x.b!=y.b)
        return x.b > y.b;
        if(x.b>=S)
        return x.c > y.c;
        return x.d > y.d;
    }

}; beb ar[50005];
vector<beb> v(0);

int main(){
    scanf("%d %d", &S, &N);
    for(int i=0;i<N;i++){
        ar[i].u = i;
        scanf("%d %d %d", &ar[i].b, &ar[i].d,&ar[i].c);

    }
    scanf("%d", &Q);
    sort(begin(ar), begin(ar)+N);
    for(int i=0, x;i<Q;i++){
        scanf("%d", &x);
        printf("%d\n", ar[x-1].u+1);
    }
    return 0;

}