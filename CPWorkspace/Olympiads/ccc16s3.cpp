#include <stdio.h>
#include <vector>
using namespace std;
int n, m;
vector<vector<int> > adj(1);
bool pho[100005];
int main(){
    scanf("%d %d", &n, &m);
    adj.resize(n);
    for(int i=0;i<m;i++){
        pho[m] = true;
    }
    for(int i=0, a, b;i<n;i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }


}