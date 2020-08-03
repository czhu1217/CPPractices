
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
string nee = "abacaba";
bool val(string t) 
{
    bool pos = 1;int cnt=0;
    for(int i=0;i+6<t.size();i++){
        pos=1;
        for(int j=0;j<7;j++){
            if(nee[j]!=t[i+j])pos=0;
        }
        if(pos){
            cnt++;
        }
    }
    if(cnt==1)return 1;

    else return 0;
}
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i=0;i+6<n;i++){
        string t; bool cont=0;
        for(int j=0;j<n;j++)t += s[j];
        for(int j=0;j<7;j++){
            if(s[i+j]!=nee[j]&&s[i+j]!='?'){ cont=1;break;}
        }
        if(cont)continue;
        for(int j=0;j<n;j++){
            if(j-i>=0&j-i<7) t[j] = nee[j-i];
            else if(t[j]=='?') t[j] = 'd';
        }
        if(val(t)){
            cout << "YES\n";
            cout << t << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}