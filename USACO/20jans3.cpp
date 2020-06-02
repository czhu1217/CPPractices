#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
int n, m;
const int MM = 1e5+2;
int cow[MM], rnk[MM], par[MM];
bool mov[MM];
vector<int> adj[MM], pro;
struct ed{
    int a, b, c;
    bool operator<(const ed &e){
        return c<e.c;
    }
};
int tar=0;
vector<ed> lst;
int find(int u){
    if(par[u]!=u) return find(par[u]);
    return u;
}
bool merge(int a, int b){
    int x = find(a), y = find(b);
    if(x==y)return false;
    if(rnk[x]>rnk[y]){
        par[y] = x; return true;
    }
    par[x] = y;
    if(rnk[y]==rnk[x])rnk[y]++;
    pro.erase(remove(pro.begin(), pro.end(), a) , pro.end()); 
    pro.erase(remove(pro.begin(), pro.end(), b) , pro.end());
    return true;
}
int main(){
    memset(mov, 0, sizeof mov);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> cow[i];
        if(cow[i]!=i){  mov[i] = true; tar++; pro.push_back(i);}
    }
    for(int i=1, u, v, w;i<=m;i++){
        cin >> u >> v >> w;
        lst.push_back({u, v, w});
    }
    sort(lst.begin(), lst.end());
    reverse(lst.begin(), lst.end());
    for(int i=1;i<=n;i++) par[i] = i;
    int cnt=1; int mi=-1;
    sort(pro.begin(), pro.end());
    for(int i=0;i<lst.size();i++){
        if(pro.empty())break;
        int a = lst[i].a, b = lst[i].b, c = lst[i].c;
        if(merge(a, b)){
            mi = c;
        }
    }
    cout << mi << "\n";
    return 0;

}