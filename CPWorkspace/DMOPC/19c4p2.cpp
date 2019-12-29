#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int rd, cd, sr, sc, er, ec, N, fwdr, fwdc, emptyr, emptyc, step=0, a, b, c, d, pre=0;
int main(){
    cin >> N;
    cin >> sr >> sc >> er >> ec;
    rd = abs(er-sr); cd = abs(ec-sc);
    if(sr>er) fwdr = -1; else fwdr = 1;
    if(sc>ec) fwdc = -1; else fwdc = 1;
    cin >> a >> b >> c >> d;
    
    if(a==sr&&b==sc){
        emptyr = c; emptyc = d; 
    }
    else{
        emptyr = a; emptyc = b;
    }
    int mi = min(rd, cd);
    step += mi*2*3-3;
    int dif = max(rd, cd) - min(rd, cd);
    if(dif>=1){
        step += 3;
        dif--;
    }
    step += dif*5;
    if(rd>cd){
        step += abs(sr+fwdr-emptyr)+abs(sc-emptyc)+1;
        if(cd==0&&((fwdr<0&&sr<emptyr&&sr>er)||(fwdr>0&&sr>emptyr&&sr<er))){
            step+=2;
            printf("uh");
        }
    }
    else{
        step += abs(sc+fwdc-emptyc)+abs(sr-emptyr)+1;
        if(rd==0&&((fwdc<0&&sc<emptyc&&sc>ec)||(fwdc>0&&sc>emptyc&&sc<ec))){
            step+=2;
            printf("lklklk");
        }
    }

    cout << step << "\n";
    return 0;


}