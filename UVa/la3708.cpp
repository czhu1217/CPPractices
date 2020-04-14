
//Graveyard NEERC2006
//legit solution
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m)==2){
        double ans = 0.0;
        for(int i=1;i<n;i++){
            double pos = (double)i/n*(n+m);
            ans += fabs(pos-floor(pos+0.5))/(n+m);
        }
        ans *= 10000;
        printf("%.4lf\n", ans);
    }
    return 0;

}