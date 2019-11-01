#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n, m, s;
vector<vector<int>> adj(1);
vector<int> pho;
queue<int> op;
int main()
{
    scanf("%d %d", &n, &m);
    adj.resize(n);
    for (int i = 0, p; i < m; i++)
    {
        scanf("%d ", &p);
        pho.push_back(p);
    }
    for (int i = 0, a, b; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        if (adj[pho[i]].size() == 1)
        {
            s = pho[i];
        }
    }
    op.push(s);
    while(!pho.empty()){

    }

}