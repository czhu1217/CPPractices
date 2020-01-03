#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int r, c, cl, cr, cs, ms, mr, ml, mu, md;
int msum = 0, sum;
bool b[402][402];
map<pair<int, int>, bool> m;
int start = 0, op[402];
char ch;
int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> ch;
            if (ch == '.')
            {
                b[i][j] = true;
            }
            else
                b[i][j] = false;
        }
    }

    sum = 0;
    msum = 0;
    for (cl = 0; cl < c; cl++)
    {
        start = 0;
        sum = 0;
        for (cr = cl; cr < c; cr++)
        {
            for (int i = 0; i < r; i++)
            {
                if (b[i][cr])
                {
                    op[i]++;
                }
                else
                {
                    op[i] = 0;
                }
            }
            for (int i = 0; i < r; i++)
            {
                if (i != 0 && op[i] == op[i - 1] && op[i - 1] != 0)
                {
                    sum = ((i - start + 1) + op[i]) * 2;
                }
                else if (op[i] != 0)
                {
                    start = i;
                    sum = op[i] * 2 + 2;
                }

                if (sum > msum)
                {
                    msum = sum;
                }
            }
        }
        memset(op, 0, sizeof(op));
    }
    cout << msum - 1;
    return 0;
}