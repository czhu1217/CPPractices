#include <stdio.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int n, bit[200000], a[200000];
void update(int idx, int val)
{
    for (int i = idx; i <= n; i += i & -i)
    {
        bit[i] += val;
    }
}

int query(int idx)
{
    int sum = 0;
    for (int i = idx; i > 0; i -= i & -i)
    {
        sum += bit[i];
    }
}

long long rangeQuery(int l, int r)
{
    return query(r) - query(l - 1);
}

int main()
{
    int q;
    scanf("%d %d", &q, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a[i]);
    }
    vector<tuple<int, int, int>> op;
    for (int i = 0; i < q; i++)
    { //loops Q times
        int l, r, k;
        scanf("%d %d %d", l, r, k);
        op.push_back(make_tuple(l, r, k));
    }
    
    sort(op.begin(), op.end());
    for(int i=0;i<q;i++){
        a[n+1] = get<0>(op[i]);    
    }
    sort(a[0], a[q+n-1]);
    for (int i = 0; i < q; i++)
    {
        long long sum = rangeQuery(get<1>(op[i]), get<2>(op[i]));
    }
}