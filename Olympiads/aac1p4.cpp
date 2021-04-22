#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 1e6+5;
int n, q, a[MM], idx[MM];
pair<pi, pi> qry[MM];
int ans[MM];
int main(){
    memset(idx, -1, sizeof idx);
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    int l, r, x;
    FOR(i, 1, q){
        cin >> l >> r >> x;
        qry[i] = {{r, l}, {x, i}};
    }
    sort(qry+1, qry+1+q);
    int it = 1;
    FOR(i, 1, n){
        idx[a[i]] = i;
        while(qry[it].f.f<=i&&it<=n){
            bool pos = 0;
            l = qry[it].f.s; r = qry[it].f.f; x = qry[it].s.f;
            FOR(j,1, sqrt(x)){
                if(x%j==0){
                    int t = x/j;
                    if(t==j) continue;
                    if(idx[j]>=l&&idx[t]>=l){
                        pos = 1;
                        break;
                    }
                }
            }
            if(pos) ans[qry[it].s.s] = 1;
            else ans[qry[it].s.s] = 0;
            it++;
        }
    }
    FOR(i, 1, q){
        if(ans[i]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}