#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    long long int n, pair, middle, left, right;
    long long int cnt = 0;
    scanf(" %lld", &n);
    long int mx = sqrt(2 * n);
    for (int i = 1; i <= mx; i++)
    {

        if (i % 2 != 0)
        {
            if (n % i == 0)
            {

                cnt++;
            }
        }
        else
        {
            if (n % (i / 2) != 0)
            {
                continue;
            }
            pair = n / (i / 2);
            if (pair % 2 != 0)
            {
                cnt++;
            }
        }
    }
    printf("%lld\n", cnt);
    return 0;
}