#include <stdio.h>
using namespace std;

struct flight{  int u, v, d;} f[20005];
int n, m, k, q;

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i=0;i<n;i++){
        scanf("%d %d %d", &f[i].u, &f[i].v, &f[i].d);
    }


}