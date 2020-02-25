#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int V, N, c[10005], ar[10005];
int main()
{
    cin >> N >> V;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &c[i]);
    }
    int pre=0, prel=0;
    for (int k = 1; k <= V; k++)
    {
        // memset(ar, 0x3f, sizeof(ar));
        int va, l;
        cin >> va >> l;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j <= va; j++)
            {
                if (j == 0)
                {
                    ar[c[i]] = 1;
                }
                else if (ar[j] > 0 && j + c[i] <= va)
                {
                    if (ar[j + c[i]] == 0)
                        ar[j + c[i]] = ar[j] + 1;
                    else
                    {
                        ar[j + c[i]] = min(ar[j] + 1, ar[j + c[i]]);
                    }
                }
                else if (j + c[i] > va)
                    break;
            }
        }
        if(ar[va]>100000) cout << -1 << "\n";
        else cout << ar[va] << "\n";
    }

    return 0;
}