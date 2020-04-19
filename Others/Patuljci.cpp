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
int main(){
    int a[10]; int sum=0;
    for(int i=1;i<=9;i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i=1;i<=9;i++){
        for(int j=i;j<=9;j++){
                if(sum-a[i]-a[j]==100){
                    for(int m=1;m<=9;m++){
                        if(m!=i&&m!=j) printf("%d\n", a[m]);
                    }
                    return 0;
                }
        }
    }
}