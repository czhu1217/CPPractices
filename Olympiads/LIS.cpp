#include <algorithm>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int N;
vector<int> lis;
int main(){
    cin >> N;
    for(int i=0, x;i<N;i++){
        scanf("%d", &x);
        if(lis.empty()||x>lis.back()) lis.push_back(x);
        else{
            *(lower_bound(lis.begin(), lis.end(), x)) = x;
        }
    }
    printf("%d\n", lis.size());

}