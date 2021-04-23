#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 2e5+5, M = 1e6+5;
int n, a[MM], b[M];

int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                b[j]++;
                if(j*j!=a[i])b[a[i]/j]++;
            }
        }
    }
    for(int i=M;i>0;i--){
        if(b[i]>1){
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}