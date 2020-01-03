#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, x;
    vector<int> v[3];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        int t = x%3;
        v[t].push_back(x);
        
    }

    // if(v[1].size()+v[2].size()+1<v[0].size()|| (!v[1].empty()&&!v[2].empty()&&v[0].empty())){
    //     cout << "impossible" << endl;
    // }

    // while(!v[1].empty()){
    //     if(v[0].size() > v[1].size()){
    //         cout << v[0].back() << " ";
    //         v[0].pop_back();
    //         cout << v[1].back() << " ";
    //         v[1].pop_back();
    //     }
    //     else cout << v[1].back() << " ";
    // }
    // while(!v[2].empty()){
    //     if(!v[0].empty()){
    //         cout << v[0].back() << " ";
    //         v[0].pop_back();
    //         cout << v[2].back() << " ";
    //         v[2].pop_back();

    //     }
    //     else cout << v[2].back() << " ";
    //     v[2].pop_back();
    // }
    // if(!v[0].empty()){
    //     cout << v[0].back() << endl;
    //     v[0].pop_back();
    // }
    // cout << endl;

    

    return 0;
}
