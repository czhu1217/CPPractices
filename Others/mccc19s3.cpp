#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
int N, Q, B, cnt;
vector<pair<int, char>> adj[100005];
string s, temp;
int mx=0, mxpos=-1;
void dfs(int n, int dis)
{
    if(dis>mx){
        mx = dis;
        mxpos = n;

    }
    for (auto e : adj[n])
    {
        if (cnt < temp.size() && temp[cnt] == e.second)
        {
            dfs(e.first, dis+1);

        }
    }
}
int main()
{
    cin >> s >> Q;
    for (int i = 2; i <= Q+1; i++)
    {
        char op;
        cin >> op;
        if (op == 'C')
        {
            int x;
            char c;
            cin >> x >> c;
            adj[x].push_back({i, c});
        }
        else
        {
            cin >> temp;
            cnt = 0;
            if (temp.size() <= s.size())
            {
                for (int k = 0; k < temp.size(); k++)
                {
                    if (temp[k] == s[k])
                        cnt++;
                    else
                        break;
                }
                if (cnt > 0)
                {
                    cout << 1 << endl;
                }
                else
                    cout << -1 << endl;
            }
            else
            {
                for (int k = 0; k < s.size(); k++)
                {
                    if (temp[k] == s[k])
                        cnt++;
                    else
                        break;
                }
                if (cnt < s.size())
                {
                    cout << 1 << endl;
                }
                else
                {
                    mx = cnt;
                    mxpos = 1;
                    dfs(1, cnt);
                    cout << mxpos << endl;
                }
            }
        }
    }
    return 0;
}