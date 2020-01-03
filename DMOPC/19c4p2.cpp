#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int rd, cd, sr, sc, er, ec, N, fwdr, fwdc, emptyr, emptyc, step=0, a, b, c, d, op=0;
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
    if(emptyr==sr) op = 1;
    else if(emptyc==sc) op = 0;
    else if(rd>cd&&cd!=0) op = 0;
    else if(rd!=0) op = 1;
    // if((rd==0||cd==0)){
    //     step -= 2;
    // }

    while(rd>0||cd>0){

        if(rd>0&&cd>0){
            
            if(op==0){
                // printf("h\n");
                step+=abs(sr+fwdr-emptyr)+abs(sc-emptyc)+1;
                rd--;
                emptyr = sr; emptyc = sc;
                sr += fwdr;
                // cout << step << "\n";
                op = 1;
            }
            else{
                // printf("v\n");
                step+=abs(sc+fwdc-emptyc)+abs(sr-emptyr)+1;
                cd--;
                emptyr = sr; emptyc = sc;
                sc += fwdc;
                // cout << step << "\n";
                op = 0;
            }
        }
        else if(rd>0){
            // printf("hh\n");
            step+=abs(sr+fwdr-emptyr)+abs(sc-emptyc)+1;
            rd--;
            if(emptyc==sc&&((fwdr<0&&sr<emptyr&&sr>er)||(fwdr>0&&sr>emptyr&&sr<er))) step+= 2;
            emptyr = sr; emptyc = sc;
            sr += fwdr;
            // cout << step << "\n";

        }
        else{
            // printf("vv\n");
            step+=abs(sc+fwdc-emptyc)+abs(sr-emptyr)+1;
                cd--;
                if(emptyr==sr&&((fwdc<0&&sc<emptyc&&sc>ec)||(fwdc>0&&sc>emptyc&&sc<ec))) step+= 2;
                emptyr = sr; emptyc = sc;
                sc += fwdc;
                // cout << step << "\n";
        }

      
    }
    cout << step << "\n";
    return 0;


}