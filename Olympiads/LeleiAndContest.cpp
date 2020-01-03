#include <iostream>
using namespace std;
typedef long long int ll;
const int MM = 2e5+5;
struct node {int l, r; ll lz, sum;} seg[3*MM];
int N, M, Q;
void pushup(int id){
    seg[id].sum = seg[2*id].sum + seg[2*id+1].sum;
}
void pushdown(int id){
    int lc = 2*id, rc = 2*id+1;
    seg[lc].lz += seg[id].lz;
    seg[lc].sum += seg[id].lz*(seg[lc].r-seg[lc].l+1);
    seg[rc].lz += seg[id].lz;
    seg[rc].sum += seg[id].lz*(seg[rc].r-seg[rc].l+1);
    seg[id].lz = 0;

}
void build(int l, int r, int id){
    seg[id].l = l;
    seg[id].r  =r;
    if(l==r){
        cin >> seg[id].sum;
        return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l, mid, 2*id);
    build(mid+1, r, 2*id+1);
    pushup(id);


}
void update(int l, int r, int val, int id){
    if(seg[id].l==l&&seg[id].r==r){
        seg[id].lz+=val;seg[id].sum += (ll)val*(r-l+1);
        return;
    }
    if(seg[id].lz!=0){
        pushdown(id);
    }
    int mid = (seg[id].l+seg[id].r)/2;
    if(r<=mid) update(l, r, val, 2*id);
    else if(l>mid) update(l, r, val, 2*id+1);
    else{
        update(l, mid, val, 2*id); 
        update(mid+1, r, val, 2* id+1);
    }
    pushup(id);

}
ll query(int l, int r, int id){
    if(seg[id].l==l&&seg[id].r==r){
        return seg[id].sum;
    }
    if(seg[id].lz!=0) pushdown(id);
    int mid = (seg[id].l+seg[id].r)/2;
    if(r<=mid) return query(l, r, 2* id);
    else if(l>mid) return query(l, r, 2*id+1);
    else{
        return query(l, mid, 2*id) + query(mid+1, r, 2*id+1);
    }

}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> Q;
    build(1, N, 1);
    for(int i=1, op, x, y, z;i<=Q;i++){
        cin >> op >> x >> y;
        if(op==1){
            cin >> z;
            update(x, y, z, 1);

        }else{
            cout <<  query(x, y, 1)%M << "\n";
        }
    }
    return 0;
    
}