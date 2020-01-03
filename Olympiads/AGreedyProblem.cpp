#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long N, M;
long long cost;
vector < pair<int, long long>> v;
int main()
{
    scanf("%d %d", &N, &M);
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end());
    // for(auto e:v){
    //     cout << e.first << " " << e.second << "\n";
    // }
    for(int i=0;i<N;i++){
        if(M==0)break;
        int t;
        t = min((long long)M, v[i].second);
        M -= t;
        // printf("%d \n", M);
        cost += t*v[i].first;

    }
    cout << cost << "\n";
    return 0;

}