#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lld;
const int MM = 1e5+5;
int N, Q;
int a[MM];

struct node{
    int l, r; lld pre, suf, ans, sum;
} seg[3*MM];

void pushup(int id){
    seg[id].pre = max(seg[id*2].pre, seg[id*2].sum+seg[id*2+1].pre);
    seg[id].suf = max(seg[id*2].suf+seg[id*2+1].sum, seg[id*2].sum+seg[id*2+1].pre);
    seg[id].ans = max(max(seg[2*id].ans, seg[2*id+1].ans), seg[2*id].suf+seg[2*id+1].pre);
    seg[id].sum = seg[id*2].sum+seg[2*id+1].sum;
}
void build(int l, int r, int id){
    seg[id].l = l;
    seg[id].r  =r;
    if(l==r){
        seg[id].ans = a[id];
        seg[id].pre = a[id];
        seg[id].suf = a[id];
        seg[id].sum = a[id];
        return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l, mid, 2*id);
    build(mid+1, r, 2*id+1);
    pushup(id);


}
node query(int l, int r, int id){
    if(seg[id].l==l&&seg[id].r==r){
        int mid = (seg[id].l + seg[id].r)/2;
        if(r<=mid){
            return query(l, r, 2*id);
        }
        else if(l>mid){
            return query(l, r, 2*id+1);
        }
        else{
            node lv = query(l, mid, 2*id), rv = query(mid+1, r, 2*id+1), ret;
            ret.pre = max(lv.pre, lv.sum+rv.pre);
            ret.suf = max(lv.suf+rv.sum, rv.suf);
            ret.sum = lv.sum+rv.sum;
            ret.ans = max(max(lv.ans, rv.ans), lv.suf+rv.pre);
            return ret;

        }
    }

}
void update(int pos, int val, int id){
    if(seg[id].l==seg[id].r){
        seg[id].pre=seg[id].suf=seg[id].ans = seg[id].sum = val;
        return;
    }
    int mid = (seg[id].l+seg[id].r)/2;
    if(pos <= mid){
        update(pos, val, 2*id);
    }
    else{
        update(pos, val, 2*id+1);
    }
    pushup(id);

}
int main(){
    cin.tie(0);cin.sync_with_stdio(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    build(1, N, 1);
        char c;
    for(int i=0, x, y;i<Q;i++){

        cin >> c >> x >> y;

        if(c=='Q'){
            cout << query(x, y, 1).ans;
        }
        else{
            update(x, y, 1);
            cout << "debug";
        }
    }
    return 0;
    
}