//Using difference array
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
struct windo
{
    int x1, x2, y1, y2, t;
} win[2001];
map<int, int> rx, ry;
vector<int> vx, vy;
int N, T, cntx, cnty; short dif[4002][4002]; int M, K, Q, x[4002], y[4002];
long long ans = 0;
long long getArea(int d)
{
    ans = 0;
    memset(dif, 0, sizeof(dif));
    memset(win, 0, sizeof(win));
    vx.clear();vy.clear();;rx.clear();ry.clear();
    for (int i = 1; i <= K; i++)
    {
        win[i].x1 = max(x[i]-d-1, 0);
        win[i].x2 = min(x[i]+d, N);
        win[i].y1 = max(y[i]-d-1, 0);
        win[i].y2 = min(y[i]+d, M);
        win[i].t = 1;
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

    for (int i = 1; i <= K; i++)
    {
        dif[rx[win[i].x1]][ry[win[i].y1]] += win[i].t;
        dif[rx[win[i].x2]][ry[win[i].y2]] += win[i].t;
        dif[rx[win[i].x1]][ry[win[i].y2]] -= win[i].t;
        dif[rx[win[i].x2]][ry[win[i].y1]] -= win[i].t;
    }
    for (int i = 1; i <= cntx; i++)
    {
        for (int j = 1; j <= cnty; j++)
        {
            dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
            if (dif[i][j] > 0)
            {
                ans += 1LL*(vx[i] - vx[i - 1]) * (vy[j] - vy[j - 1]);
            }
        }
    }

    return ans;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >>K;
    for(int i=1;i<=K;i++){
        cin >> x[i] >> y[i];

    }
    cin >> Q;
    if(Q==0){
        cout << K << "\n";
        return 0;
    }
    cout << getArea(Q) - getArea(Q-1)<< "\n";
    return 0;
}