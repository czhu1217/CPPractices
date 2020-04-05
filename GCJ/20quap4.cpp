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
using namespace std;
typedef long long ll;
int T, B;
bool a[102];
int a1, a2;
int main(){
    cin >> T >> B;
    for(int t=1;t<=T;t++){
        memset(a, 0, sizeof a);
        a1=a2=0;
        string ans;
        int count=0;
        for(int i=1;i<=B/2;i++){
            if(count%10==0){
                int choice = 4;
                if(a1&&a2){
                    cout << a1 << endl;
                    bool t1, t2;
                    cin >> t1;
                    count++;
                    cout << a2 << endl;
                    cin >> t2;
                    count++;

                    bool same = (t1==a[a1]), dif = (t2==a[a2]);
                    if(same&&dif) choice = 4;
                    else if(same&&!dif) choice = 2;
                    else if(!same&&dif) choice = 3;
                    else choice = 1;
                }
                else if(a1){
                    cout << a1 << endl;
                    bool temp = false;
                    cin >> temp;
                    count++;
                    cout << 1 << endl;
                    bool temp2; cin >> temp2;
                    count++;

                    if(temp!=a[a1]) choice = 1;
                }
                else if(a2){
                    cout << a2 << endl;
                    bool temp = false;
                    cin >> temp;
                    count++;
                    cout << 1 << endl;
                    bool temp2; cin  >> temp2;
                    count++;

                    if(temp!=a[a2]) choice = 1;

                }
                else choice = 4;
                switch(choice){
                    case 1:
                    for(int k=1;k<=B;k++) a[k] = !a[k];
                    break;
                    case 2:
                    for(int k=1;k<=B/2;k++){
                        bool t = a[k];
                        a[k] = a[B-k+1];
                        a[B-k+1] = t;
                    }
                    break;
                    case 3:
                    for(int k=1;k<=B;k++) a[k] = !a[k];
                     for(int k=1;k<=B/2;k++){
                        bool t = a[k];
                        a[k] = a[B-k+1];
                        a[B-k+1] = t;
                    }
                    break;
                }
            }
            cout << i << endl;
            cin >> a[i];
            count++;
             
            int suf = B-i+1;
            cout << suf << endl; cin >> a[suf] ;
            count++;
            if(a[i]==a[suf]) a1 = i;
            else a2 = i; 
        }
        for(int i=1;i<=B;i++) ans += a[i]+'0';
        cout << ans << endl;
        char ok; cin >> ok;
        if(ok=='N')return 0;
    }
    return 0;


}