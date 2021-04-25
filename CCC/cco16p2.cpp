#include <bits/stdc++.h>
#include <math.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 4004;
struct pt{
    int x, y, w;
} p[MM];
int n; ll sum;
long double calc(pt x, pt y){
    int dx = y.x - x.x;
    int dy = y.y - x.y;
    return atan2(dy/abs(__gcd(dx, dy)), dx/abs(__gcd(dx, dy)));
}
const long double PI = 3.14159265358979323846;
ll ans;
int main(){
    cin >> n;
    FOR(i, 0, n-1) cin >> p[i].x >> p[i].y >> p[i].w;
    FOR(i, 0, n-1){
        sum=0;
        map<long double, int> angle;
        FOR(j, 0, n-1){
            if(j==i) continue;
            sum += p[j].w;
            angle[calc(p[i], p[j])] += p[j].w;
        }
        vector<pair<long double, int>> v;
        for(auto e:angle){
            v.pb(e);
        }
        for(auto e:angle){
            v.pb({e.f+2*PI, e.s});
        }
        int k = 0; ll sum1 = 0, res2, res1;
        for(int j=0;j<angle.size();j++){
            long double lmt = v[j].f + PI;
            while(v[k].f < lmt&&k<v.size()){
                sum1 += v[k].s;
                k++;
            }

            // cout << sum1 << "\n";
            res1 = sum1;
            res2 = sum - sum1;
            if(abs(v[k].f-lmt)<=1e-10){
                res1 += v[k].s;
            }

            res1 += p[i].w; res2 += p[i].w;
            ans = max(ans, max(res1, res2));
            sum1 -= v[j].s;



        }
    }
    cout << ans << "\n";
    return 0;
}