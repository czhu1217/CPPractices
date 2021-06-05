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
    int a[5];
    void solve(){
        cin >> a[1] >> a[2] >> a[3] >> a[4];
        int a1 = max(a[1], a[2]);
        int b1 = max(a[3], a[4]);
        sort(a+1, a+1+4);
        int x, y;
        if(a1<b1) swap(a1, b1);
        if(a1==a[4]&&b1==a[3]) cout << "YES\n";
        else cout << "NO\n";


        


    }
    int main(){
        int t; cin >> t;
        while(t--)solve();
        return 0;
    }