#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, par[100005], rnk[100005];
int d, cnt;
int days;
struct ed
{
    int a, b, c, d;
    bool operator<(const ed &e) const
    {
        return c < e.c || (c == e.c && d < e.d);
    }
};
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
vector<ed> aa;
bool ehc = false;
int maxc;
int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        if (i < n)
            aa.push_back({a, b, c, 0});
        else
            aa.push_back({a, b, c, 1});
    }
    sort(aa.begin(), aa.end());

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    int i;
        maxc = 0;

    for (i = 0; i < aa.size(); i++)
    {
        if (cnt == n - 1)
        {
            break;
        }
        if (merge(aa[i].a, aa[i].b))
        {
            maxc = aa[i].c;
            cnt++;

            if (aa[i].d)
            {

                days++;
            }

        }
    }
    if (aa[i - 1].d)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
        for (int i = 0; i < aa.size(); i++)
        {
            auto e = aa[i];
            if (find(e.a) != find(e.b))
            {
                if (e.c < maxc || (e.c == maxc && !e.d))
                    merge(e.a, e.b);
                else if (!e.d && e.c <= d)
                {
                    printf("%d\n", days - 1);
                    return 0;
                }
            }
        }
    }

    printf("%d\n", days);
    return 0;
}