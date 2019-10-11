#include <iostream>
#include <string>
#define EPS 1e-9
using namespace std;
double consumption, dis, init, initCon, prevDis=0;
int leakCount;

bool can(double x){
    string event;
    cin >> event;
    if(event.compare("Fuel consumption")==0){
        cin >> consumption;
        return can(x);
    }
    cin >> dis;
    x -= (dis-prevDis)*(consumption/100+leakCount);
    prevDis = dis;
    if(x<0)
        return false;
    if(event.compare("Leak")==0){
        leakCount++;
        return can(x);
    }
    if(event.compare("Gas station")){
        x = init;
        return can(x);
    }
    if(event.compare("Mechanics")==0){
        leakCount==0;
        return can(x);
    }
    if(event.compare("Goal")==0){
        return true;
    }
}

    int main(){
        double high=10000.0, low=0.0, mid, ans;
        while(fabs(high-low)>EPS){
            mid = (high+low)/2;
            if(can(mid)){
                ans = mid;
                high = mid;
            }
            else{
                low = mid;
            }
        }




    }

    
        
    
    





