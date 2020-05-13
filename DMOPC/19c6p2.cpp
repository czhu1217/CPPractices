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
#include <climits>
typedef long long ll;
#define f first
#define s second
using namespace std;
int a, b;
int ans = INT_MAX;
vector<int> fac;
int m[1000003], ans1[1000003];
void primeFac(int n)  
{  
    while (n % 2 == 0)  
    {  
       m[2]++;
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            m[i]++;
            n = n/i;  
        }  
    }   
    if (n > 2)  
        m[n]++;
}  
int main(){
    int temp;
    memset(m, 0, sizeof m);
    cin >> a >> b;
    temp = a;
    primeFac(a);
    for(int i=1;i<=1e6+2;i++){
        if(m[i]!=0){
            int t = i;
            while(t<=b){
                ans1[i] += b/t;
                t *= i;
            }
        }
    }
    for(int i=1;i<=1e6+2;i++){
        if(m[i])
        ans = min(ans1[i]/m[i], ans);
    }

    cout << ans << "\n";
    return 0;
}