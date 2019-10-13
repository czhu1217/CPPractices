#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int d, v, w,  t[6], counter;
vector<int> key;
bool work;
queue<pair<int, int>> q;
int main()
{
    scanf("%d", &w);
    scanf("%d", &d);
    key.resize(d);
    for (int i = 0; i < d; i++)
    {
        scanf("%d", &key[i]);
    }
    sort(key.begin(),key.end());
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        scanf("%d", &t[i]);
    }
    while(!q.empty()){
        int t = q.back().first;
        q.pop();
        for(int i=key.size()-1;i>=0;i--){
            if(t%key[i]==0) q.push(make_pair(t/key[i], counter));
        }

    }

}

