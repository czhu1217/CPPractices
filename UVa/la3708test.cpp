//my attempt to graveyard, slightly more intuitive than legit solution.
//aye it works
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m)==2){
        double goal = 10000.0/(m+n); double ans = 0.0;
        for(int i=1;i<n;i++){
            double pos = 10000.0/n*i;
            int q = pos/goal;
            ans += min(pos-q*goal, (q+1)*goal-pos);
        }
        printf("%.4lf\n", ans);
    }
    return 0;
}