#include <bits/stdc++.h>
using namespace std; 
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 1e5+5;
int n, m, t;
pi a[MM]; int ans; int c[10005], k, res, tmp;
priority_queue<int, vector<int>, greater<int>> pq;
int sml = 0;
int main(){
    // cin.sync_with_stdio(0); cin.tie(0);
    scanf("%d %d %d", &n, &m, &t);
    FOR(i, 1, n) scanf("%d %d", &a[i].f, &a[i].s);
    sort(a+1, a+1+n);
    int mx = 0, cnt;
    res = 0;
    FOR(i, 1, n){
        tmp = m - a[i].f*2;

        if(tmp<t) break;
        pq.push(a[i].s);
        res += a[i].s;
        mx = max(mx, a[i].s);
        k = tmp/t;
        cnt=min(i,k);
        while(pq.size()>cnt){
            res -= pq.top();
            pq.pop(); 
        } 
        ans = max(ans, res);


    }
    printf("%d\n", ans);


    return 0;
}