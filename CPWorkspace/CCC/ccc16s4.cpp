#include <stdio.h>
#include <vector>
#define lld long long int
using namespace std;
const int INF = 1000001;
int N;
bool ar[400][400];
lld ans = 0;
vector<lld> a;
int main()
{
    scanf("%d", &N);
    a.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &a[i]);
        if(a[i]>ans) ans = a[i];
    }


}
