#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int N, Q, cnt=0, r[100005], vis[100005], connect[100005];
vector<vector<int>> adj;

bool flag, pre = false;
void dfs(int a){
    vis[a] = true;
    for(auto e:adj[a]){ 
        if(!vis[e]){
            dfs(e);
        }
    }

}

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
int main(){
    cin >> N >> Q;
    adj.resize(N+2);
    memset(r, 0, sizeof(r));
    for(int i=1, a,b, x;i<=Q;i++){
        flag = false;
        cin >> a >> b >> x;
        if(i==1){
            connect[a] = true;
            connect[b] = true;
        }
        if(r[a]%2&&x%2) cnt--;
        else if(r[a]%2==0&&x%2) cnt++;
        r[a] += x;
        if(r[b]%2&&x%2) cnt--;
        else if(r[b]%2==0&&x%2) cnt++;
        r[b] += x;
        adj[a].push_back(b);
        adj[b].push_back(a);
     
     
        memset(vis, false, sizeof(vis));
        if(pre&&(connect[a]||connect[b])&&(cnt==0||cnt==2)){
            cout << "YES\n";
            connect[a] = true;
            connect[b] = true;
            pre = true;
            continue;
        }
        dfs(a);
        for(int i=1;i<=N;i++){
            if(!adj[i].empty()&&!vis[i]){
                cout << "NO" << "\n";
                pre = false;
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        if (cnt == 2 || cnt == 0)
        {
            cout << "YES\n";
            pre = true;
        }
        else
        {
            cout << "NO\n";
            pre = false;
        }

    

    }
    return 0;
}