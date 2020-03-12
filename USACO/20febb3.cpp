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
int cow[100005], pos[100005];
int main()
{
    //  ifstream cin("swap.in");
    //  ofstream cout("swap.out");

    cin >> N >> K;
    cin >> l[0] >> r[0];
    cin >> l[1] >> r[1];
    for (int i = 1; i <= N; i++)
    {
        int cyc = 1;
        int temp = i;
        if (temp >= l[0] && temp <= r[0])
            temp = l[0] + r[0] - temp;
        if (temp >= l[1] && temp <= r[1])
            temp = l[1] + r[1] - temp;
        while (temp != i)
        {
            cyc++;
            if (temp >= l[0] && temp <= r[0])
                temp = l[0] + r[0] - temp;
            if (temp >= l[1] && temp <= r[1])
                temp = l[1] + r[1] - temp;
            
        }
        for(int j=0; j<K%cyc; j++){
            if (temp >= l[0] && temp <= r[0])
                temp = l[0] + r[0] - temp;
            if (temp >= l[1] && temp <= r[1])
                temp = l[1] + r[1] - temp;
        }
        pos[temp] = i;
    }
    for(int i=1; i<=N;i++){
        cout << pos[i] << "\n";
    }

    return 0;
}