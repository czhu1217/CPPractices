#include <stdio.h>
#include <cstring>
#include <iostream>
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
int N;
struct point{
    int x, y;
};
int orientation(point p, point q, point r) 
{ 

    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
bool onSegment(point p, point q, point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
}
  
bool intersect(point p1, point q1, point p2, point q2){
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false;
}
int main(){
    point p1, p2;
    scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
    cin >> N;
    int ans=0;
    bool touch = 0;
    for(int i=1;i<=N;i++){
        int x; cin >> x; int above=0;
        touch = 0;
        point a[1005];
        for(int j=1;j<=x;j++){
           cin >> a[j].x >> a[j].y;

        }
        for(int j=1;j<=x;j++){
            for(int k=j+1;k<=x;k++){
                if(intersect(p1, p2, a[j], a[k])){
                    touch = 1;
                    break;
                }
            }
            if(touch)break;
        }
        if(touch){ans++;}
    }
    cout << ans << "\n";
    return 0;
}