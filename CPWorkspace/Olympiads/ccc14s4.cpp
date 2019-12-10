//Using difference array
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
struct windo
{
    int x1, x2, y1, y2, t;
} win[1001];
map<int, int> rx, ry;
vector<int> vx, vy;
int N, T, cntx, cnty, dif[2002][2002];
long long ans = 0;
int main()
{
    scanf("%d %d", &N, &T);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d %d %d %d", &win[i].x1, &win[i].y1, &win[i].x2, &win[i].y2, &win[i].t);
        rx[win[i].x1] = rx[win[i].x2] = 0;
        ry[win[i].y1] = ry[win[i].y2] = 0;
    }
    cntx = 1;
    cnty = 1;
    for (auto &it : rx)
    {
        it.second = cntx++;
        vx.push_back(it.first);
    }
    for (auto &it : ry)
    {
        it.second = cnty++;
        vy.push_back(it.first);
    }

    for (int i = 1; i <= N; i++)
    {
        dif[rx[win[i].x1]][ry[win[i].y1]] += win[i].t;
        dif[rx[win[i].x2]][ry[win[i].y2]] += win[i].t;
        dif[rx[win[i].x1]][ry[win[i].y2]] -= win[i].t;
        dif[rx[win[i].x2]][ry[win[i].y1]] -= win[i].t;
    }
    for (int i = 1; i < cntx; i++)
    {
        for (int j = 1; j < cnty; j++)
        {
            dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
            if (dif[i][j] >= T)
            {
                ans += 1LL*(vx[i] - vx[i - 1]) * (vy[j] - vy[j - 1]);
            }
        }
    }
 

    printf("%lld\n", ans);
    return 0;
}