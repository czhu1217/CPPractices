#include <bits/stdc++.h>
using namespace std; 
typedef pair<long long, long long> pi;
#define FOR(i, a, b) for (long long i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const long long MM = 5e5+5, MN=1e5+5;
long long bit[MM], bit2[MN], n,m, a[MN];
long long query(long long pos){
    long long sum=0;
    for(long long i=pos;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}

void update(long long pos, long long v){
    for(long long i=pos; i<=n;i+=i&-i){
        bit[i]+=v ;
    }
}
long long query2(long long pos){
    long long sum=0;
    for(long long i=pos;i>0;i-=i&-i){
        sum+=bit2[i];
    }
    return sum;
}

void update2(long long pos, long long v){
    for(long long i=pos; i<=MN;i+=i&-i){
        bit2[i]+=v ;
    }
}
int main(){
    cin >> n >> m;
    FOR(i, 1, n){
        cin >> a[i];
        update(i, a[i]);
        update2(a[i], 1);
    } 
    char c; long long x, y;
    while(m--){
        cin >> c >> x;
        if(c=='C'){
            cin >> y;
            y = y-a[x];
            update(x, y);
            update2(a[x], -1);
            a[x] += y;
            update2(a[x], 1);

        }
        else if(c=='S'){
            cin >> y;
            cout << query(y) - query(x-1) << "\n";
        }
        else{
            cout << query2(x) << "\n";
        }
    }
    return 0;
}