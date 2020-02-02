#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
int N, Q, cnt = 0, r[100005], vis[100005], connect[100005];
vector<vector<int>> adj;
queue<int> pro;

bool flag;
bool connected(int a)
{
    // cout << "at " << a << endl;
    vis[a] = true;
    if (connect[a])
        return true;

    for (auto e : adj[a])
    {
        if (!vis[e] && connected(e))
        {
            connect[a] = true;
        }
    }
    if (connect[a])
        return true;
    return false;
}
int main()
{
    cin >> N >> Q;
    adj.resize(N + 2);
    memset(r, 0, sizeof(r));
    for (int i = 1, a, b, x; i <= Q; i++)
    {
        flag = false;
        cin >> a >> b >> x;
        if (i == 1)
        {
            connect[a] = true;
            connect[b] = true;
        }
        if (r[a] % 2 && x % 2)
            cnt--;
        else if (r[a] % 2 == 0 && x % 2)
            cnt++;
        r[a] += x;
        if (r[b] % 2 && x % 2)
            cnt--;
        else if (r[b] % 2 == 0 && x % 2)
            cnt++;
        r[b] += x;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(cnt!=0&&cnt!=2){
            cout << "NO\n";
            continue;
        }

        memset(vis, false, sizeof(vis));
        if (!connected(a))
        {
            flag = true;
            pro.push(a);
            pro.push(b);
            cout << "NO\n";
            continue;
        }
        else
        {
            connect[a] = true;
            connect[b] = true;
        }
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < pro.size(); i++)
        {
            int t = pro.front();
            pro.pop();
            if (!connected(t))
            {
                flag = true;
                pro.push(t);
                break;
            }
        }
        if (flag)
        {
            cout << "NO\n";
            continue;
        }

        if (cnt == 2 || cnt == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}