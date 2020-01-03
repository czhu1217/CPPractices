#include <iostream>
#include <math.h>
#include <algorithm>
#include <numeric>
using namespace std;
const int MM =1e5+2;
struct node{  int l, r, v, g, f;} seg[3*MM];
int N, M, a[MM];
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
void push_up(int id){
    seg[id].v = min(seg[2*id].v, seg[2*id].v );
    seg[id].g = gcd(seg[2*id].g, seg[2*id+1].g);
}

void buildTree(int *a,int index,int s,int e)
{
	//base case
	if(s>e)
		return;
	//reached leaf node
	if(s==e)
	{
		tree[index]=a[s];
		return ;
	}
	//now build the segment tree in bottom up manner
	int m = (s+e)/2;
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	tree[index]= max(tree[2*index],tree[2*index+1]);
	return;
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
int qryGcd(int l, int r, int id){
    if(seg[id].l==l&&seg[id].r==r)return seg[id].v;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r<=mid)return qryGcd(1, r, 2*id);
    if(l>mid) return qryGcd(l, r, 2*id+1);
    return gcd(qryGcd(l, mid, 2*id), qryGcd(mid+1, r, 2*id+1));
}
int qryCnt(int l, int r, int g, int id){
    if(seg[id].l==l&&seg[id].r == r) return seg[id].g==g? seg[id].f:0;
    int mid = (seg[id].l+seg[id].r)/2;
    if(r<=mid) return qryCnt(l, r, g, 2*id);
    if(l>mid){
        return qryCnt(l, r, g, 2*id+1);
    }
    return qryCnt(l, mid, g, 2*id)+qryCnt(mid+1, r, g, 2*id+1);
}
void update(int pos, int val, int id){
    if(seg[id].l==pos&&seg[id].r ==pos){
        seg[id].v = seg[id].g = val;return;
    }
    int mid = (seg[id].l+seg[id].r)/2;
    if(pos<=mid)update(pos, val, 2*id);
    else{
        update(pos, val, 2*id+1);
    }
    push_up(id);
}
int main(){
    char op;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    build(1, N, 1);
    for(int i=1, x, y;i<=M;i++){
        cin >> op >> x >> y;
        if(op=='C') update(x, y, 1);
        if(op=='M') cout << qryMin(x, y, 1) << "\n";
        if(op == 'G') cout << qryGcd(x, y, 1);
        if(op=='Q') cout << qryCnt(x, y, qryGcd(x, y, 1), 1)<<"\n";
    }
    return 0;

}


