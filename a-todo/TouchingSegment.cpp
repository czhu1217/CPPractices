#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> pi;
#define f first
#define s second
const int MM = 1e5+5;
struct node{int l, r, val, lz;} seg[6*MM];
int T, N; pi a[MM]; vector<int> lft[2*MM], rit[2*MM], p;
void build(int l, int r, int rt){
    seg[rt].l=l; seg[rt].r = r;
    if(l==r){lft[l].clear(); rit[l].clear(); return;}

    int mid = (l+r)/2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);


}
void push_down(int rt){
    seg[2*rt].lz += seg[rt].lz; seg[2*rt+1].lz += seg[rt].lz;
    seg[2*rt].val += seg[rt].lz; seg[2*rt+1].val += seg[rt].lz;
    seg[rt].lz=0;
}
void update(int l, int r, int v, int rt){
    if(seg[rt].l==l&&seg[rt].r==r){
        seg[rt].val+=v; seg[rt].lz+=v;return;
    }
    if(seg[rt].lz)push_down(rt);
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(r<=mid)update(l, r, v, 2*rt);
    else if(l>mid)update(l, r, v, 2*rt+1);
    else{
        update(l, mid, v, 2*rt);
        update(mid+1, r, v, 2*rt+1);
    }
    seg[rt].val = max(seg[2*rt].val, seg[2*rt+1].val);
}
int main(){
    cin >> T;
    for(int t=1;t<=T;t++){
        memset(seg, 0, sizeof seg);p.clear();
        scanf("%d", &N); int ans=0, cnt=0, line=0;
        for(int i=0; i<N; i++){
            scanf("%d %d", &a[i].f, &a[i].s);
            p.push_back(a[i].f); p.push_back(a[i].s);
        }
        sort(p.begin(), p.end()); p.resize(unique(p.begin(), p.end()) - p.begin());
        build(0, p.size()-1, 1);
        for(int i=0; i<N; i++){
            a[i].f = lower_bound(p.begin(), p.end(), a[i].f) - p.begin();
            a[i].s = lower_bound(p.begin(), p.end(), a[i].s) - p.begin();
            update(a[i].f, a[i].s, 1, 1);lft[a[i].f].push_back(i); rit[a[i].s].push_back(i);
        }
        for(int j=0; j<p.size(); j++){
            for(int i: lft[j]){
                line++; update(a[i].f, a[i].s, -1, 1);
            }
            ans = max(ans, line+seg[1].val);
            for(int i: rit[j]){
                line--; update(a[i].f, a[i].s, 1, 1);
            }
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
    
}