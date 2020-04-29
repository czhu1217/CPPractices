#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <climits>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5+5; int N;
#define f first
#define s second
struct node{
    int i, x, y, v;
    bool operator<(const node &e){
        return x<e.x;
    }
}a[MM];
int main(){
    cin >> N;
    for(int i=1, x, y, v;i<=N;i++){
        scanf("%d%d%d",&a[i].x,  &a[i].y, &a[i].v);
        a[i].i=i;
    }
    sort(a+1, a+N+1);
    for(int i=1;i<=N-1;i++){
        if(a[i].v==a[i+1].v&&a[i+1].v==a[i+1].v)continue;
        printf("%d %d %d\n", a[i].i, a[i+1].i, a[i+2].i);
        return 0;
    }
    printf("-1\n");
    return 0;
    
    
    

}