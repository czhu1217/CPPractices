#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 2505;
ll n, ans; int g[MM][MM], yi[MM], xi[MM];
set<set<int>> tot;
struct cow{
    int id, x, y;
} a[MM];
bool comp(cow a, cow b){
    return a.x<b.x;
}
bool compy(cow a, cow b){
    return a.y<b.y;
}
int main(){
    scanf("%lld", &n);
    FOR(i, 1, n){
        scanf("%d %d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    sort(a+1, a+1+n, comp);
    FOR(i, 1, n){
        a[i].x = i;
    }
    sort(a+1, a+1+n, compy);
    FOR(i, 1, n) a[i].y = i;
    // FOR(i, 1, n){
    //     g[a[i].x][a[i].y] = a[i].id;
    // }
    // FOR(i, 1, n) cout << a[i].x << " " << a[i].y << "\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    FOR(i, 1, n){
                xi[a[i].y] = a[i].x;
                yi[a[i].x] = a[i].y;
    } 
    FOR(i, 1, n) cout << a[i].x << " " << a[i].y << "\n";
    cout << "\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int i2 = i; i2<=n;i2++){
                for(int j2 = j; j2<=n;j2++){
                    if(xi[j2]<=i&&xi[j2]>=i2){
                        cout << i << " " << j << " " << i2<< " " << j2 << "\n";
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}