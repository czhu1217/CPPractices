#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int n, m, tp=-1, bcc, cnt,  dfn[MM], low[MM], stk[MM], sz[MM], head[MM];
bool in[MM];int ans;
struct edge{int v, nxt;} e[2*MM];
void add(int u, int v){
    e[cnt].v = v;e[cnt].nxt=head[u];head[u]=cnt++;
}
void tarjan(int u, int p){
    dfn[u] = low[u] = ++cnt;
    stk[++tp]=u;in[u]=1;
    for(int i=head[u];i!=-1;i=e[i].nxt){
        int v = e[i].v;
        if(v==p)continue;
        if(!dfn[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int tmp=0, x=0;
        do{
            x = stk[tp--];
            tmp++;
            in[x]=0;
        }while(x!=u);
        sz[++bcc]=tmp;
    }
}
int main(){
    cin >> n >> m;
    memset(head, -1, sizeof head);
    for(int i=1, u, v;i<=m;i++){
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for(int i=1;i<=bcc;i++){
        ans += 1LL*sz[i]*(n-sz[i]);
    }
    cout << ans/(1LL*(n*(n-1))) << "\n";
}