#include <stdio.h>
#include <vector>
#define lld long long int
using namespace std;
const int INF = 1000001;
int N, sml;
vector<lld> a;
void combine2(int e){
    a[e]+=a[e+1];
    vector<lld>::iterator it = a.begin()+e+1;
    a.erase(it);
    }
void combine(int e){
    combine(e);
    combine(e);
}
bool pos (int i){
    if(a[i+2] )
}
int main()
{
    scanf("%d", &N);
    a.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &a[i]);
        if(a[i]<INF&&pos(i)){
            sml = a[i];
        }

    }

}
