#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int T, N, a[100005];
bool flag;
vector<int> river, branch;
int main()
{
    cin >> T;
    river.push_back(0);
    for (int i = 0; i < T; i++)
    {
        river.clear();
        branch.clear();
        flag = false;
        memset(a, 0, sizeof(a));
        cin >> N;
        for (int j = N-1; j >= 0; j--)
        {
            cin >> a[j];
        }
        for (int j = 0, x; j < N; j++)
        {
            x = a[j];
            if (river.back() == x - 1 || (river.empty() && x == 1))
            {
                river.push_back(x);
                while (true)
                {
                    if (branch.back() == river.back() + 1)
                    {
                        int t = branch.back();
                        branch.pop_back();
                        river.push_back(t);
                    }
                    else
                        break;
                }
            }
            else
            {
                if (branch.empty() || x < branch.back()) branch.push_back(x);
                else
                {
                    cout << "N\n";
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
            cout << "Y\n";
    }
    return 0;
}