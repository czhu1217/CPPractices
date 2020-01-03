#include <stdio.h>
#include <vector>
using namespace std;
int n, s, q;
char op;
vector<pair<int, vector<int>>> st;
int main()
{
    scanf("%d %d", &n, &s);
    st.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", st[i].first);
    }
    for (int i = 0; i < s; i++)
    {
        int l, t;
        scanf("%d %d", &l, &t);
        st[l].second.push_back(t);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a;
        scanf("%c", op);
        int idx;
        scanf("%d", &idx); 
        scanf("%d", &a);
        if(op=='a'){
 
            st[idx].second.push_back(a);
            
        } 
        else if(op=='s'){
            vector<int>::iterator id = find(st[idx].second.begin(), st[idx].second.end(), a);
            if(id!=st[idx].second.end()){
                st[idx].second.erase(id);

            } 
            
        }
    }
}