#include <stdio.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#define lld long long int
using namespace std;
long double P, nr;
lld Y, T;
long double N;
int main()
{
    scanf("%llf %lld %lld", &P, &Y, &T);

    long double r = P / 100;

    N = (1 + r) * (1 - pow(1 + r, Y)) / (1 - (1 + r));

    lld target = ceil(T / N);
    if(target==0){
        printf("1");
        return 0;
    }

    long double nr = T / N;
    long double cnr = nr;

    lld ct;

    ct = 0;
    cnr = 0;
    for (lld i = 0; i < Y; i++)
    {
        ct = (ct + target) * (1 + r);
        cnr = (cnr + nr) * (1 + r);

        
        if (ct >= T)
            break;
        if (cnr - ct > 0.999)
        {
            printf("%lld", target + 1);
            return 0;
        }

    }
    printf("%lld", target);

    return 0;
}