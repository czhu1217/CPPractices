#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
using namespace std;
#define f first;
#define s second;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e6 + 2;
int N, T, L;
int dif[MM];
vector<pair<pi, int>> qu;
int main()
{
    cin >> N >> T;
    memset(dif, 0, sizeof(dif));
    for (int i = 1, a, b, w; i <= T; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        dif[a] += w;
        dif[b + 1] -= w;
    }
    cin >> L;
    for (int i = 1; i <= N; i++)
    {
        dif[i] += dif[i - 1];
    }

    ll tot = 0, cnt = 0, ans=0;
    bool flg = false;
    for (int i = 1; i <= N; i++)
    {
        flg = false;

        while (tot + dif[i] > L)
        {
            if (cnt == 0)
            {
                tot = 0;
                flg = true;
                break;
            }
            tot -= dif[i - cnt];
            cnt--;
        }
        if (!flg)
        {
            tot += dif[i];
            cnt++;
        }
        if(cnt>ans) ans = cnt;
    }
    cout << ans << "\n";
    return 0;
}