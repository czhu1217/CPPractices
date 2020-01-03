#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n;
vector<unordered_set<int>> r;
vector<int> fac;
int main(){
    scanf("%d", &n);
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            fac.push_back(i);
            if(n/i!=i) fac.push_back(n/i);
        }
    }
    sort(fac.begin(), fac.end());
    r.resize(fac.size());
    r[0].insert(0);
    for(int i=0;i<fac.size();i++){
        for(int j=0;j<i;j++){
            if(fac[i]%fac[j]==0){
                for(int k:r[j]){
                    r[i].insert(k+fac[i]/fac[j]-1);
                }

            }
        }
    }
    set<int> final;
   
    for(int i:r.back()){
        final.insert(i);
    }
    printf("%d\n", final.size());
    for(int i:final){
        printf("%d ", i);
    }

    return 0;
}

  
