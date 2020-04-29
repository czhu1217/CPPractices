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
int N, Q;
int a[202];
int main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= Q; i++)
    {
        int v, l, r;
        scanf("%d %d %d", &v, &l, &r);

        sort(a + l, a + r+1);
        if (v == 2)
            reverse(a + l, a + r+1);

    }
    for (int i = 1; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[N]);
    return 0;
}