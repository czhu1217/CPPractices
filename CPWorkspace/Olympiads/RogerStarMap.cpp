#include <stdio.h>
using namespace std;
int N, bit[32005], lvl[15000];
void update(int pos, int val)
{
    for (int i = 1; i <= 32005; i += i&-i)
    {
        bit[i] += val;
    }
}
int query(int pos)
{
    int ret = 0;
    for (int i = pos; i > 0; i -= i&-i)
        ret += bit[i];
    printf("Return %d\n", ret);
    return ret;
}
int main()
{
    scanf("%d", &N);
    for (int i = 1, x, y; i <= N; i++)
    {
        scanf("%d %d", &x, &y);
        x++;
        lvl[query(x)]++;
        update(x, 1);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", lvl[i]);
    }
    return 0;

}
