#include <iostream>
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
typedef long long ll;
using namespace std;
int x1, y11, x2, y2, x3, y3, x4, y4;
pair<int, int> sa, sb;
int b1, b2;
int main(){
    scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    int a1 = y11-y2, b1=x2-x1, c1=-1*(a1*x1+b1*y11);
    int a2 = y3-y4, b2=x4-x3, c2=-1*(a2*x3+b2*y3);
    if(a1*b2==a2*b1){
        if(b1*c2==b2*c1)
            printf("coincident\n");
        else printf("parallel\n");
    }
    else{
        double x =  (double)(b1*c2-b2*c1)/(b2*a1-b1*a2)*1.0, y = (double)(a1*c2-a2*c1)/(a2*b1-a1*b2)*1.0;
        printf("%.8f %.8f\n", x,y );
    }
    return 0;
}
