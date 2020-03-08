
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int MM = 3e5 + 5;
int n, k, a[MM], ans;
ll psa[MM];
bool check(int x)
{
    ll mi = 0;
    for (int i = 1; i <= n; i++)
    {
        psa[i] = psa[i - 1] + a[i] - x;
        if (i >= k)
        {
            mi = min(mi, psa[i - k]);
            if (psa[i] - mi >= 0)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] *= 1000;
    }
    int lo = 1, hi = 1e9;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    printf("%.4f\n", ans/1000.0);
    return 0;
}