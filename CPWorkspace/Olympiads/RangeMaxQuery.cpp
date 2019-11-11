#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
#define lld long long int
const int MX = 100005;
int N, M, l, r;
lld a[MX], tree[MX*4];
void buildTree(lld *tree,lld *a,int index,int s,int e)
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

//function to query the segment tree for RMQ
int query(lld *tree,int index,int s,int e,int qs,int qe)
{
	//base case: if query range is outside the node range
	if(qs>e || s>qe)
		return INT_MIN;
	//complete overlap
	if(s>=qs && e<=qe)
		return tree[index];
	//now partial overlap case is executed
	int m = (s+e)/2;
	int left_ans = query(tree,2*index,s,m,qs,qe);
	int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
	return max(left_ans,right_ans);
}

//function to update a value at position to "pos"
void updateNode(int *tree,int index,int s,int e,int pos,int val)
{
	if(pos<s || pos>e)
		return ;
	if(s==e)
	{
		tree[index] = val;
		return ;
	}
	int m = (s+e)/2;
	updateNode(tree,2*index,s,m,pos,val);
	updateNode(tree,2*index+1,m+1,e,pos,val);
	tree[index] = max(tree[2*index],tree[2*index+1]);
	return;
}

//function to update the values in a range
void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc)
{
	//query range outside the node range
	if(s>re || e<rs)
		return;
	if(s==e)
	{
		tree[index] += inc;
		return ;
	}
	int m = (s+e)/2;
	updateRange(tree,2*index,s,m,rs,re,inc);
	updateRange(tree,2*index+1,m+1,e,rs,re,inc);
	tree[index] = max(tree[2*index],tree[2*index+1]);
	return;
}

int main(){

    scanf("%d %d", &N, &M);
    int index = 1;													//index of 1st node
    int s =0,e=N-1;
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    buildTree(tree, a, 1, 0, N-1);

    for(int i=0;i<M;i++){
        scanf("%d %d", &l, &r);
        printf("%d\n", query(tree,1, 0, N-1, l, r-1));
    }
    return 0;

}