#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long ll;
int a[1002], ind[1002];
int main()
{
    for (int t = 1; t <= 10; t++)
    {
        deque<int> v;

        int N;
        cin >> N;
        int sum = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &a[i]);
            ind[a[i]] = i;
            v.push_back(a[i]);
        }
        int cnt = 1;
        for (int i = N - 1; i > 0; i--)
        {
            if (ind[i] > ind[i + 1])
            {
                break;
            }
            cnt++;
        }
        for (int i = N - cnt; i > 0; i--)
        {
            int ans;

            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] == i)
                {
                    ans = j;
                    break;
                }
            }
            v.erase(v.begin() + ans);
            sum += ans;
            v.push_front(i);
        }
        cout << sum << "\n";
    }
    return 0;
}