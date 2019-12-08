#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef pair<int, int> pi;
vector<pi> v;
int N, x, y;
int main() {
    int N; cin >> N;
    pi coor[N];
    double min = 0;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        coor[i].first = aqt;
        coor[i].second = bqt;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                ld a = sqrt( pow(P[i].first - P[j].first, 2.0) + pow(P[i].second - P[j].second, 2.0) );
                ld b = sqrt( pow(P[j].first - P[k].first, 2.0) + pow(P[j].second - P[k].second, 2.0) );
                ld c = sqrt( pow(P[k].first - P[i].first, 2.0) + pow(P[k].second - P[i].second, 2.0) );

                ld area = (a+b+c)/2.0;
                ld dist = 0;
                
                if(a*a+b*b-c*c<0 || b*b+c*c-a*a < 0 || c*c+a*a-b*b < 0) {
                    dist = max({a, b, c});
                }
                else
                    dist = (a*b*c) / sqrt(area*(area-1)*(area-b)*(area-c));
                if(dist > min) 
                    min = dist;
            }
        }
    }
    cout << fixed << setprecision(2) << min << endl;
}