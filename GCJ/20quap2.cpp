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
#include <fstream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
int T;

int main(){
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    string s;
    cin >> s;
    int v = 0, cur;
    printf("Case #%d: ", t);
    for (int i = 0; i < s.size(); i++)
    {
      cur = s[i]-'0' - v;
      while(cur!=0){
        if(cur>0){
          printf("(");
          cur--;
        }else{
          printf(")");
          cur++;
        }
      }
      v = s[i]-'0';
      printf("%d", v);
    }
    cur = 0 - v;
    while(cur!=0){
      if(cur>0){
        printf("(");
        cur--;
      }else{
        printf(")");
        cur++;
      }
    }
    printf("\n");
  }
  return 0;
}