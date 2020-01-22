#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
ll N, K, x, cnt;
int main(){
    // ifstream fin("race.in");
    // ofstream cout("race.out");
    cin >> K >> N;
    for(int i=1;i<=N;i++){
        cin >> x;
        int spd = 1, pos = 1;
        cnt = 1;
        int left = K;

        left -= 1;
        while(left > 0){
          if((spd+1+x)*(spd+1-x+1)/2<=left){
              spd++;
              left -= spd;
          } 
          else if((spd+x)*(spd-x+1)/2<=left) {
              left -= spd;
          }else{
              spd--;
              left -= spd;
          }
          cnt++;
        }
        cout << cnt << endl;
    }
        return 0;


}