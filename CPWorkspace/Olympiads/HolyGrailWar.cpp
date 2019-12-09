#include <stdio.h>
#include <iostream>

#include <algorithm>

const int MM = 100002;
#define lc id<<1
#define rc id<<1|1
typedef long long int lld;
struct node{
    int l, r; lld pre, suf, ans, sum;
} seg[3*MM];

int N, Q;
char op;


void pushup(int id){
    seg[id].pre = max(seg[lc].pre, seg[lc].sum+seg[rc].pre);
    seg[id].suf = max(seg[lc].suf+seg[id*2+1].sum, seg[rc].suf);
    seg[id].ans = max(max(seg[2*id].ans, seg[2*id+1].ans), seg[2*id].suf+seg[2*id+1].pre);
    seg[id].sum = seg[id*2].sum+seg[2*id+1].sum;
}
void build(int l, int r, int id){
    seg[id].l = l;
    seg[id].r  =r;
    if(l==r){
        scanf("%lld", &seg[id].pre);
        seg[id].suf = seg[id].sum = seg[id].ans = seg[id].pre;
        return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l, mid, 2*id);
    build(mid+1, r, 2*id+1);
    pushup(id);


}
node query(int l, int r, int id){
    if(seg[id].l==l&&seg[id].r==r)return seg[id];
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
void update(int pos, int val, int id){
    if(seg[id].l==seg[id].r&&seg[id].l==pos){
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
    scanf("%d %d", &N, &Q);
     build(1, N, 1);

    for(int i=0, x, y;i<Q;i++){

        scanf(" %c %d %d", &op, &x, &y);

        if(op=='Q'){
            printf("%lld\n", query(x, y, 1).ans);
        }
        else{
            update(x, y, 1);
            
        }
    }
    return 0;
    
}