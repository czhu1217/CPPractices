#include <iostream>
const int MM =1e5+2;
struct node{  int l, r, v, g;} seg[3*MM];
int N, M, a[MM];
void push_up(int id){
    seg[id].v = min(seg[2*id].v, seg[2*id].v );
    seg[id].g = __gcd(seg[2*id].g, seg[2*id+1].g);
}
void build(int l, int r, int id){
    seg[id].l = l;seg[id].r = r;
    if(l==r){
        seg[id].v = seg[id].g = a[l];return;}

    int mid = (seg[id].l+seg[id].r)/2;
    build(l, mid, 2*id);
    build(mid+1, r, id*2+1);
    push_up(id);
}

int qryMin(int l, int r, int id){
    if(seg[id].l==l&&seg[id].r==r)return seg[id].v;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r<=mid)return qryMin(1, r, 2*id);
    if(l>mid) return qryMin(l, r, 2*id+1);
    return min(qryMin(l, mid, 2*id), qryMin(mid+1, r, 2*id+1));
}
int qryMin(int l, int r, int id){
    if(seg[id].l==l&&seg[id].r==r)return seg[id].v;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r<=mid)return qryMin(1, r, 2*id);
    if(l>mid) return qryMin(l, r, 2*id+1);
    return min(qryMin(l, mid, 2*id), qryMin(mid+1, r, 2*id+1));
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    build(1, N, 1);
    for(int i=1, x, y;i<=M;i++){
        cin >> op >> x >> y;
        if(op=='C') update(x, y, 1);
        if(op=='M') cout << qryMin(x, y, 1) << "\n";
    }

}


