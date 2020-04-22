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
#include <climits>
using namespace std;
typedef long long ll;
int a[200004];
int main()
{
    int N;
    ll M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }
    int l = 1, r = 1;
    ll sum = 0;
    int ans = 0;
    for (; r <= N; r++)
    {
        if (a[r] >= M)
        {
            l = r + 1;
            sum = 0;
            continue;
        }

        while (sum + a[r] >= M)
        {
            sum -= a[l];
            l++;
            if (sum == 0)
                break;
        }

        sum += a[r];

        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}