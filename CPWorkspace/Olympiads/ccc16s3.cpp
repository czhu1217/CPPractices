#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n, m, s, si, cnt, lv[100005], step = 0;
vector<vector<int>> adj(1);
map<int, bool> pho;
queue<int> op, path;

int main()
{
    scanf("%d %d", &n, &m);
    adj.resize(n);
    cnt = m;
    for (int i = 0, p; i < m; i++)
    {
        scanf("%d ", &p);
        pho[p] = true;
    }
    for (int i = 0, a, b; i < n-1; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (pho[i]&&adj[i].size() == 1)
        {
            s = i;

        }
    }
    path.push(s);
    lv[s] = 0;
    while(cnt!=0){

        int t = path.front();
        if(pho[t]==true){
            pho[t] = false;
            cnt--;
            step += lv[t];
            lv[t] = 0;
            clear(path);
            path.push(t);

            
        }
        path.pop(); 
        for(int i=0;i<adj[t].size();i++){
            path.push(adj[t][i]);
            lv[adj[t][i]] = lv[t]+1;
        }
    }

    printf("%d\n", step);
    return 0;

}