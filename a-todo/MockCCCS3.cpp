#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef  long long ll;
vector<string> vs; int cnt = 0, mx = 0, maxpos=-1;
int Q;
string ss, s, nw;
int main(){
    cin >> s >> Q;
    vs.push_back(s);
    for(int i=0; i<Q;i++){
        char c ;
        cin >> c;
        if(c=='C'){
            int pos; char ch;
            cin >> pos >> ch;
            nw = vs[pos] + ch;
            vs.push_back(nw);
        }
        else{
            cin >> ss;
            maxpos = -1;
            mx = 0;
            for(i=1;i<vs.size();i++){
 
                cnt = 0;
                for(int j=0;j<min(ss.size(),vs[i].size());j++){
                    if(vs[i][j]==ss[j]) cnt++;
                    else break;
                }
                if(cnt>mx){
                    mx=cnt;
                    maxpos = i;
                if(mx==ss.size()){
                    break;
                }
            }}
            cout << maxpos << endl;

        }
    }
    return 0;

 

}