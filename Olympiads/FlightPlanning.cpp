#include <stdio.h>
#include <vector>

using namespace std;

struct flight{  int u, v, d;} f[20005];
int n, m, k, q;
bool hub[20005];
vector<vector<pair<int, int>>> adj(1);

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &q);
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &f[i].u, &f[i].v, &f[i].d);
        adj[f[i].u].push_back({f[i].v, f[i].d});
    }
    for(int i=0;i<k;i++){
        int temp;
        scanf("%d", &temp);
        hub[temp]=true;
    }
    for(int i=0;i<q;i++){

    }


}