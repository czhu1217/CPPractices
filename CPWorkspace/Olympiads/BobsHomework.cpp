#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    long long int n, pair, middle, left, right;
    long long int idk = 0, cnt = 0;
    scanf("%lld", &n);

    for (long long int i = 1; i <= n; i++){
        if(i%2!=0){
            if(n%i!=0) continue;
            middle = n/i;
            left = middle - i/2;
            right = middle + i/2;
            if(left>0&&right<=n) cnt++;
        }
        else{
            pair = n/(i/2);
            if(pair%2==0){
                continue;
            }
            middle = pair/2;
            left = middle - i/2;
            right = middle + i/2 + 1;
            if(left>0&&right<=n) cnt++;
        }
    }
    printf("%lld", cnt);
    return 0;
}