#include <bits/stdc++.h>
const double M_PI = 3.141592653589793238;
using namespace std;
typedef long long ll;
void solve(){
    int n; cin >> n; 
    long double ta = tan((double)2*M_PI/(double)(4*n));
    double ans = 0.5/ta;
    ans *= 2;
    printf("%.10f\n", ans);


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}
