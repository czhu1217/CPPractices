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
typedef long long ll;
int N, M, K;
int l[102], r[102];
int cow[100005];
bool vis[100005];
int main()
{
    //  ifstream cin("swap.in");
    //  ofstream cout("swap.out");

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cow[i] = i;
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> l[i] >> r[i];
    }
    for (int j = 1; j <= M; j++)
    {
        int le = l[j], ri = r[j];
        for (int k = 0; k <= (int)(ri - le) / 2; k++)
        {
            int temp = cow[le + k];
            cow[le + k] = cow[ri - k];
            cow[ri - k] = temp;
        }
    }

    for (int i = 1; i <= N; i++)
    {

        if (!vis[i])
        {
            vis[i] = true;
            int temp = cow[i];
            vector<int> v;
            v.push_back(i);
            while (temp != i)
            {
                vis[temp] = true;
                v.push_back(temp);
                temp = cow[temp];
            }
            int rem = K % v.size();
            for (int j = 0; j < v.size(); j++)
            {
                cow[v[j]] = v[(j + rem) % v.size()];
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << cow[i] << endl;
    }
    return 0;
}