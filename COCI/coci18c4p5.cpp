// alien's trick, monotonic deque, binary search
//coci18c4p5
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 1e5+5;
const ld lmt = 1e-12;
int n,k,cnt[MM];
deque<int> dq;
ld dp[MM];
inline ld slope(int x,int y)
{
    return (dp[x] - dp[y]) / (x - y);
}
int check(ld cost)
{
    dq.clear();dq.pb(0);
    for(register int i = 1;i <= n;++i)
    {
        while(dq.size()>=2&&slope(dq[0], dq[1])>1.0/i) dq.pop_front();
        int best = dq[0];
        dp[i] = dp[best] + (ld)(i - best) / i - cost,cnt[i] = cnt[best] + 1;
        while(dq.size()>=2&&slope(dq[dq.size()-2], dq[dq.size()-1])<slope(dq[dq.size()-1], i)) dq.pop_back();
        dq.pb(i);
    }
    return cnt[n];
}
int main()
{
    cin >> n >> k;
    ld l, r, mid;
    l = 0,r = 1e6;
    while(r-l>=lmt){
        mid = (l + r) / 2;
        if(check(mid)>=k)
            l = mid;
        else
            r = mid;
    }
    check(l);
    double ans= dp[n] + k * mid ;
    printf("%.9f\n",ans);
    return 0;
}