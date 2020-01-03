#include <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>
using namespace std;
int sz;
#define lld long long int
lld N, Q, a[4000005];
int lt[18][4000005], rt[4000005];
int l, r, LOG, n;
map<int, int> pre, after;
void findLeft(){
    for(int i=1;i<=N;i++){
        lt[0][i] = min(i-pre[a[i]], lt[0][i-1]+1);
        pre[a[i]] = i;
    }
}
void findRight(){
    for(int i=N;i>=1;i--){
        if(after[a[i]]==0){
            after[a[i]] = N+1;
        }
        rt[i] = min(after[a[i]]-i, rt[i+1]+1);
        after[a[i]] = i;
    }
}

 
int query(int L, int R) 
{ 
  
    int j = (int)log2(R - L + 1); 
    return max(lt[j][l], lt[j][r-(1<<j)+1]);
} 
int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    LOG = log2(N);
    lt[0][0] = 0;
    rt[0] = 0;
    findLeft();
    findRight();


    for(int i=1;i<=LOG;i++){
        for(int j=1;j+(1<<i)-1<=N;j++){
            lt[i][j] = max(lt[i-1][j], lt[i-1][j+(1<<(i-1))]);

        }
    }
    for(int i=0;i<Q;i++){
        cin >> l >> r;
        int sz = r-l+1;
        if(rt[l]<sz)
        printf("%d\n",max(query(l+rt[l], r), rt[l]));
        else
        {
            printf("%d\n", sz);
        }
        
    }
    return 0;

}
// lld N, Q;
// lld arr[200005];
// int l[200005], rs[200005], ls[18][200005], LOG= 18;
// map<int, int> pre;
// int query(int l,int r){
//     int k = (int)log2(r-l+1);
//     return max(ls[k][l], ls[k][r-(1<<k)+1]);
// }
// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     cin >> N >> Q;
//     for(int i=1;i<=N;i++){
//         cin >> arr[i];
//         l[i] = min(l[i-1]+i, i-pre[arr[i]]);
//         ls[0][i] = l[i];
//         pre[arr[i]] = i;



//     }
//     pre.clear();
//     for(int i=N;i>0;i--){
//         int t = (pre.count(arr[i])?pre[arr[i]]:N+1);
//         rs[i] = min(rs[i+1]+1, t-i);
//         pre[arr[i]] = i;
//     }
//     for(int i=1;i<=LOG;i++){
//         for(int j=1;j+(1<<i)-1<=N;j++){
//             ls[i][j] = max(ls[i-1][j], ls[i-1][j+(1<<(i-1))]);

//         }
//     }
//     for(int i=1,l,r;i<=Q;i++){
//         cin >> l >> r;
//         sz = r-l+1;
//         if(rs[l]<sz){
//             cout << max(rs[l], query(l+rs[l], r)) << endl;
//         }
//         else{
//             cout << r-l+1 << endl;
//         }

//     }
//     return 0;

