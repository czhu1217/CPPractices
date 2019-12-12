//2d range query
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int N, M;
bool dif[10005][10005];
long long ans = 0;
int main()
{
    memset(dif, false, sizeof(dif));
    scanf("%d %d", &N, &M);
    for (int i = 0, x, y, w, h; i < M; i++)
    {
        scanf("%d %d %d %d", &x, &y, &w, &h);
        x++;
        y++;
        dif[x][y] = !dif[x][y];
        dif[x][y + h] = !dif[x][y+h];
        dif[x + w][y + h] = !dif[x+w][y+h];
        dif[x + w][y] = !dif[x+w][y];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(dif[i-1][j]^dif[i][j-1]^dif[i][j]){
                dif[i][j] = !dif[i-1][j-1];
            }
            else{
                dif[i][j] = dif[i-1][j-1];
            }
            if (dif[i][j])
            {
                ans++;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}