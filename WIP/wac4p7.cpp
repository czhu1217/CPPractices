#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define f first
#define s second
int n, m, par[100005], rnk[100005]; pair<int, int> qu[300005];
int q;
map<int, bool> imp;
struct ed
{
    int a, b, d, t;
    bool operator<(const ed &e) const
    {
        return t < e.t || (t == e.t && d > e.d);
    }
};vector<ed> aa;
int find(int n)
{
    if (par[n] != n)
    {
        return find(par[n]);
    }
    return n;
}
bool merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x == y)
        return false;
    if (rnk[x] > rnk[y])
    {
        par[y] = x;
        return true;
    }
    par[x] = y;
    if (rnk[y] == rnk[x])
    {
        rnk[y]++;
    }

    return true;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        int a, b, d, t;
        scanf("%d %d %d %d", &a, &b, &d, &t);
        aa.push_back({a, b, d, t});

    }
    sort(aa.begin(), aa.end());

for(int i=1;i<=q;i++){
    scanf("%d %d", &qu[i].f, &qu[i].s);
}
sort(qu+1, qu+q+1);
for(int k=1;k<=q;k++){
    int mid, mxt, cnt=0;
    mid = qu[k].f;  mxt = qu[k].s;
    if(imp[mid]){
        printf("NO\n");
        continue;
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    for (int i = 0; i < aa.size(); i++)
    {
        if (cnt == n - 1)
        {
            break;
        }
        if(aa[i].t<=mxt&&aa[i].d>=mid){
        if (merge(aa[i].a, aa[i].b))
        {
            cnt++;
        }
        }
    }
    if(cnt==n-1)printf("YES\n");
    else{ printf("NO\n"); imp[mid]=true;}


}
    return 0;
}