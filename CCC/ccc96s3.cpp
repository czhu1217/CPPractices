#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
int q, n, k; bool ar[35];
void fun(int a, int b){
    if(a>n&&b==k){
        FOR(i, 1, n) cout << ar[i];
        cout << "\n";
        return;
    }
    if(a>n) return;
    if(b<k){
        ar[a] = 1;
        fun(a+1, b+1);
    }
    ar[a] = 0;
    fun(a+1, b);
}
int main(){
    cin >> q;
    FOR(i, 1, q){
        cin >> n >> k;
        cout << "The bit patterns are" << "\n";
        fun(1, 0);
        cout << "\n";
    }
    return 0;
}