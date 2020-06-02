
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
#define f first
#define s second
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
int n, a[102], x, y;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    cin >> x >> y;
    if(x%2==0) x++;
    if(y%2==0)y--;
    int ans=0, id; int it=1; int st=1, best=0;
    if(x<a[1]){
        id = x;
        best = a[1]-x;
    }
    if(y>a[n]){
        if(y-a[n]>best){
            id = y;
            best = y-a[n];
        }
    }
    for(int i=2;i<=n;i++){
        int temp, cur;
        temp = (a[i]+a[i-1])/2;
        if(temp%2==0)temp++;
        cur = min(temp-a[i-1], a[i]-temp);
        if(temp>=x&&temp<=y){
            if(cur>best){ id = temp; best=cur;}
        }
        if(a[i]>y){
            temp = y;
            cur = min(temp-a[i-1], a[i]-temp);
            if(cur>best){ id = temp; best=cur;}
            break;
        }
    }
    cout << id << '\n';

}
int main(){
    solve();
    return 0;
}