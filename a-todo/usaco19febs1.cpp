
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
int cow[2][100005], pos[100005], pos2[100005], cow2[2][100005];
int main()
{
    ifstream cin("swap.in");
    ofstream cout("swap.out");
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cow2[0][i] = i;
        cow[0][i] = i;
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
            int temp = cow2[0][le + k];
            cow2[0][le + k] = cow2[0][ri - k];
            cow2[0][ri - k] = temp;
        }
    }

    int cnt = 1, cur = 1, pre = 0, cur2 = 1, pre2 =0;
    for (int i = 1; i <= N; i++)
    {
        pos[cow2[0][i]] = i;
    }

    for (int i = 0; i <= 2; i++)
    {
        if ((K >> i) & 1)
        {
            for (int j = 1; j <= N; j++)
            {
                cow[cur][pos[j]] = cow[pre][j];
            }
     
          swap(cur, pre);
        }
       
            for (int j = 1; j <= N; j++)
            {
                cow2[cur2][pos[j]] = cow2[pre2][j];
            }
    
        
        for (int j = 1; j <= N; j++)
        {
            pos[cow2[cur2][j]] = j;
        }
 
        swap(cur2, pre2);
    }
    for(int i=1;i<=N;i++){
        cout << cow[pre][i] << "\n";
    }

    return 0;
}