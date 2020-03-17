#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int n;
const int MM = 1e4;
vector<pi> x[MM*2+1], y[MM*2+1];
pair<long long, long long> su[100005];
int ans = 0;
int mo = 1e9+7;
ll mod(ll a) 
{ 
    return (a%mo + mo) % mo; 
} 
int main()
{
    cin >> n;
    for (int i = 0, bx, by; i < n; i++)
    {
        cin >> bx >> by;
        bx += MM; by += MM;
        x[bx].push_back({by, i});
        y[by].push_back({bx, i});
    }
    for(int i=0;i<MM*2+1;i++)
{
    if(y[i].size()){
        sort(y[i].begin(), y[i].end());
        ll sum = 0;
        for(int j=0;j<y[i].size();j++){
           sum = mod(sum- y[i][0].first + y[i][j].first );
        }
        for(int j=0;j<y[i].size();j++){
            if(j) sum = mod(sum + mod((2*j-y[i].size())*(y[i][j].first-y[i][j-1].first)));
            su[y[i][j].second].first = sum;
        }

    }
}
for(int i=0; i<MM*2+1;i++){
    if(x[i].size()){
        int sum = 0;
        sort(x[i].begin(), x[i].end());
        for(int j=0;j<x[i].size();j++){
            sum =mod(mod(mod(sum + x[i][j].first) - x[i][0].first));

        }
        for(int j=0;j<x[i].size();j++){
            if(j) sum = mod(sum + mod((2*j-x[i].size())*(x[i][j].first-x[i][j-1].first)));
            su[x[i][j].second].second = sum;
        }



    }
}
for(int i=0;i<n;i++){
    ans = mod(mod(ans)+(mod(su[i].first*(su[i].second))));
}
cout << ans << "\n";
return 0;
}