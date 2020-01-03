#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
vector<int> x, y;
map<int, int> m;
int h,v, t1, t2;


long long counter;
int main(){
    scanf("%d %d", &h, &v);
    x.resize(h);
    y.resize(v);
    for(int i=0;i<h;i++){
        scanf("%lld", &x[i]);
    }
    for(int i=0;i<v;i++){
        scanf("%lld", &y[i]);
    }
    for(int i=0;i<h-1;i++){
        for(int j=i+1;j<h;j++){
            m[x[j]-x[i]]++;
        }
    }
    for(int i=0;i<v-1;i++){
        for(int j=i+1;j<v;j++){
            counter+=m[y[j]-y[i]];
        }
    }
    printf("%lld", counter);
    return 0;


}
