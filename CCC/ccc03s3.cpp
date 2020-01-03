#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int flr, r, c, cnt, id, counter;
bool room[26][26], vis[26][26];
vector<int> rm;
int dfs(int x, int y, int id)
{
    vis[x][y] = true;
    cnt++;
    if (x - 1 >= 0 && x-1<r&& room[x - 1][y] && !vis[x - 1][y])   dfs(x - 1, y, id); 
    if (x + 1 <= r && x+1>0&& room[x + 1][y] && !vis[x + 1][y]) dfs(x + 1, y, id); 
    if (y + 1 <= r && y+1>0&&room[x][y + 1] && !vis[x][y + 1])  dfs(x, y + 1, id);  
    if (y - 1 >= 0 && y-1<r&&room[x][y - 1] && !vis[x][y - 1])  dfs(x, y - 1, id);
    return cnt;
}
int main()
{
    scanf("%d %d %d", &flr, &r, &c);
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char ch;
            scanf(" %c", &ch);
            if (ch == '.') room[i][j] = true;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && room[i][j])
            {
                cnt = 0;
                id++;
                int num = dfs(i, j, id);
                rm.push_back(num);
            }
        }
    }
    sort(rm.begin(), rm.end());
    reverse(rm.begin(), rm.end());
    for(auto e:rm){
        if(flr>=e){
            flr -= e;
            counter++;
        } 
        else break;
    }
    if(counter==1) printf("%d room, %d square metre(s) left over\n", counter, flr);
    else printf("%d rooms, %d square metre(s) left over\n", counter, flr);
    return 0;
}