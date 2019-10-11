#include <stdio.h>
using namespace std;
int h,v;
long long counter;
long long x[1502], y[1502];
int main(){
    scanf("%d %d", &h, &v);  
    for(int i=0;i<h;i++){
        scanf("%lld", &x[i]);
    }
    for(int i=0;i<v;i++){
        scanf("%lld", &y[i]);
    }
    int prev = 1;
    bool found = false;
    for(int i=0;i<h-1;i++){
        for(int j=i+1;j<h;j++){
            prev = 1;
            int dh = x[j]-x[i];
            for(int m=0;m<v-1;m++){
                for(int n=prev;n<v;n++){
                 int dv = y[n]-y[m];
                    if(dv>dh){
                        prev = n;
                        if(n==m+1) prev++;
                        break;
                    }
                    if(dv==dh){
                        counter++;
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    printf("%lld", counter);
    return 0;


}