#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, par[100005], rnk[100005];
long long int d;
int days = 0;
struct ed
{
    int a, b, c, d;
    friend bool operator<(ed &a, ed &b)
    {
        if (a.c == b.c)
            return b.d < a.d;
        return a.c < b.c;
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
int t = -1;
int main()
{
    scanf("%d %d %lld", &n, &m, &d);
    int cnt = n, mi;
    long long cost;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        if (i < n && c > d && !ehc)
        {
            c -= d;
            ehc = true;
        }
        aa.push_back({a, b, c, i < n});
    }
    sort(aa.begin(), aa.end());
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < aa.size(); i++)
    {
        if (merge(aa[i].a, aa[i].b))
        {
            cost+=aa[i].c;

            if (!aa[i].d)
            {
                days++;
            }
            cnt--;
        }
        if (cnt <= 1)
        {
            t = i;
            mi = days;
            break;
        }
    }
    int t1 = t;
    long long co;
    if (!ehc)
    {
        while (aa[++t].c - d < aa[t1].c)
        {
            days = 0;
            cnt = n;
            aa[t].c -= d;
            sort(aa.begin(), aa.end());
            for (int i = 1; i <= n; i++)
            {
                par[i] = i;
            }

            for (int i = 0; i < aa.size(); i++)
            {
                if (merge(aa[i].a, aa[i].b))
                {
                    co+=aa[i].c;

                    if (!aa[i].d)
                    {
                        days++;
                    }
                    cnt--;
                }
                if (cnt <= 1)
                {
                    break;
                }
            }
            if(co<cost){
                cost = co;
                mi = days;
            }
        }
    }

    printf("%d\n", mi);
    return 0;
}