#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
long long n, mx, counter, previ, t;
long long num[2005], amt[4005];

int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        num[t]++;
    }
    for (int i = 0; i <= 2000; i++)
    {
        if (num[i])
        {
            for (int j = i; j <= 2000; j++)
            {
                if (i == j)
                {
                    amt[i + j] += num[i] / 2;
                    if(amt[i+j]>mx) mx = amt[i+j];
                }
                else if (num[j])
                {
                    amt[i + j] += min(num[i], num[j]);
                    if(amt[i+j]>mx) mx = amt[i+j];
                }

            }
        }
    }
    for(int i=0;i<=4000;i++){
        if(amt[i] == mx){
            counter++;
        }
    }
    printf("%lld %lld", mx, counter);
    return 0;
}
