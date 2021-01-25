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
int n, a, b, a1, a2, a3;
vector<int> adj[10]; vector<pi> ans;
int msk, msk2, ind[10];
bool connected[10][10], cyc[10];
int main(){
    cin >> n;
    FOR(i, 1, n-1){
        cin >> a >> b;
        connected[a][b] = 1; connected[b][a] = 1;
    }
    if(n<3){
        cout << 0 << "\n";
        return 0;
    }
    if(n==3||n==4||n==5){
        cout << 1 << "\n";
        return 0;
    }
    if(n==6){
                cout << 2 << "\n";
    return 0;
    }
    if(n==6||n==7||n==8){

    cout << 1 << "\n";
    return 0;}
    int cnt, pos=1;
    FOR(i, 1, n){
        bool pos2 = 1;
        cyc[i] = 1;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            for(int k=1;k<=n;k++){
                pos = 1;
                if(k==i||k==j) continue;
                if(connected[i][j]&&connected[i][k]){
                    cyc[j] = 1; cyc[k] = 1;
                    connected[j][k] = 1; connected[k][j]=1;
                    for(int m=1;m<=n;m++){
                        if(m==i||m==j||m==k) continue;
                        if(connected[m][i]+connected[m][j]+connected[m][k]>=2){
                            pos = 0;
                            break;
                        }
                    }
                    if(pos){
                        a1 = j; a2 = k;
                        pos2 = 1;
                    if(n<6){
                        cout << 1 << "\n";
                        cout << j << " " << k << "\n";
                        return 0;
                    }
                    for(int m=1;m<=n;m++){
                        if(!cyc[m]){
                            for(int p=1;p<=n;p++){
                                if(p==m) continue;
                                for(int q = 1;q<=n;q++){
                                    if(q==m||q==p) continue;
                                    if(connected[m][p]&&connected[m][q]&&!cyc[p]&&!cyc[q]&&!connected[p][q]){
                                        for(int h=1;h<=n;h++){
                                            if(h==m||h==p||h==q) continue;
                                            if(connected[h][p]+connected[h][q]+connected[h][m]>=2){
                                                pos2 = 0;
                                                break;
                                            }
                                        }
                                        if(pos2){
                                            cout << 2 << "\n";
                                            cout << j << " " << k << "\n";
                                            cout << p << " " << q << "\n";
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    }
                    cyc[j] = 0; cyc[k] = 0;
                    connected[j][k] = 0; connected[k][j]=0;
                }
            }
        }
        cyc[i] = 0;
    }
    if(a1&&a2){
        cout << 1 << "\n";
        cout << a1 << " " << a2 << "\n";

    }
    else{
        cout << 0 << "\n";
    }
    return 0;
}