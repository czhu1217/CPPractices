#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
typedef long long ll;
#define f first
#define s second
using namespace std;
const int MM = 1e5 + 2;
vector<pair<int, int>> pi;
int n, q, m[MM], v[MM], a[MM], query[MM];
int find(int idx)
{
    if (a[idx]!=0)
        return a[idx];
    if (v[idx] == 0)
    {
        return m[idx];
    }
    return m[idx] + find(v[idx]);
}
int main()
{
    cin >> n >> q;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1, a, b; i <= q; i++)
    {
        cin >>a >> b;
        query[i] = b - a;
    }
    for (int i = 1; i <= n; i++)
        if (a[i]==0)  a[i] = find(i);
    
    for(int i=1;i<=q;i++){
        if(query[i]<=0){
                cout << -1 << endl;
                continue;
            }
        int ans=-1;
        for(int j=1;j<=n;j++){
            if(a[j]>=query[i]){
                ans = j;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}