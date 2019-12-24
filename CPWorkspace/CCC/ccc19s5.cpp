#include <stdio.h>
using namespace std;
int N, op, r, c, t, bit[2001][2001], mod = 1e9 + 7;
long long ans;
void upd(int k, int pos, int val)
{
    for (int i = pos; i < 2001; i += i & -i)
        bit[k][i] += val;
}
int sum(int k, int pos)
{
    int ret = 0;
    for (int i = pos; i; i -= i & -i)
        ret += bit[k][i];
    return ret;
}
int main()
{
    scanf("%d",&N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d %d %d", &op, &r, &c, &t);
        if (op == 1) upd((r + c), r, t);
        else ans = (ans + sum(r + c, r) - sum(r + c, r - t - 1) + mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}