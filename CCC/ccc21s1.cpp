#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 1e4+5;
int n; int a[MM], w[MM];
double ans = 0;
int main(){
    cin >> n;
    FOR(i, 1, n+1){
        cin >> a[i];
    }
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 1, n){
        ans += (a[i]+a[i+1])*w[i];
    }
    ans /= 2.0;
    printf("%.2f\n", ans);
    return 0;
}