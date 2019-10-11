#include <stdio.h>
#include <vector>
#include <tuple>
#include <iostream>
#include <math.h>
using namespace std;
int x, y, z, n, counter = 0;
vector<tuple<int, int, int>> pi;
float distance(int x, int y, int z)
{
    return sqrt(x * x + y * y + z * z);
}

int main()
{
    int a, b, c;

    scanf("%d %d %d %d", &x, &y, &z, &n);
    for (int i = 0; i < n; i++)
    {
        int flag = false;
        scanf("%d %d %d", &a, &b, &c);
        float dis = distance(a - x, b - y, c - z);
        for (int i = 0; i < pi.size(); i++)
        {
            int m = get<0>(pi[i]), n = get<1>(pi[i]), o = get<2>(pi[i]);

            printf("%d %d %d \n %d %d %d \n \n", a, b, c, m, n, o);
            printf("%f %f %f \n", dis,distance(a - m, b - n, c - o), distance(m - x, n - y, o - z) );
            cout << "dif " << distance(a - m, b - n, c - o) + distance(m - x, n - y, o - z) - dis << " " << distance(a - m, b - n, c - o) + dis - distance(m - x, n - y, o - z) << endl;
            bool b1 = distance(a - m, b - n, c - o) + distance(m - x, n - y, o - z) - dis < 0.0000001;
            bool b2 = distance(a - m, b - n, c - o) + distance(m - x, n - y, o - z) - dis > -0.0000001;
            bool b3 = distance(a - m, b - n, c - o) + dis < distance(m - x, n - y, o - z) +0.0000001;
            bool b4 = distance(a - m, b - n, c - o) + dis > distance(m - x, n - y, o - z) - 0.0000001;
            if((b1&&b2)||(b3&&b4)){
                flag = true;
                break;
            }


            
        }

        if (!flag)
        {
            pi.push_back(make_tuple(a, b, c));
            counter++;
        }
    }

    printf("%d\n", counter);

    return 0;
}
