#include <stdio.h>
//testing
using namespace std;
int d, v, w, key[10], t[6], counter;
bool work;
int main()
{
    scanf("%d", &w);
    scanf("%d", &d);
    for (int i = 0; i < d; i++)
    {
        scanf("%d", &key[i]);
    }
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        scanf("%d", &t[i]);
    }
    for (int k = 0; k < v; k++)
    {
        while (t[k] != 1)
        {
            for(int i=0;i<d;i++){
                if(t[k]%key[i]==0){
                    t[k] /= key[i];
                    counter++;
                }
            }


        }
    }
}

void reduce(){
    if(counter>w) return;
    

}

