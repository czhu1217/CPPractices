#include <stdio.h>
#include <iostream>
using namespace std;
long long N, Q, a[1000003], x, pre[1000005], suf[1000005];
int main()
{
    scanf("%lld %lld ", &N,&Q);
    pre[1] = 1;
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld ", &a[i]);
    }
    long long mx = a[1];
    for (int i = 2; i <= N; i++)
    {
        if (a[i] > mx)
        {
            mx = a[i];
            pre[i] = i;
        }
        else
            pre[i] = pre[i - 1];
    }
    suf[N] = N;
    mx = a[N];

    for (int i = N - 1; i >= 1; i--)
    {
        if (a[i] > mx)
        {
            mx = a[i];
            suf[i] = i;
        }
        else
            suf[i] = suf[i + 1];
    }

    for (int i = 0; i < Q; i++)
    {
        scanf("%lld", &x);
        printf("%lld %lld\n", pre[x-1], suf[x+1]);
    }
    return 0;
}