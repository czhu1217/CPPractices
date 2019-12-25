#include <stdio.h>
#include <iostream>
#include <algorithm>
int flr, r, c;
bool room[26][26];
int main()
{
    scanf("%d %d %d", &flr, &r, &c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char ch;
            scanf(" %c", &ch);
            if (ch == 'I')
            {
                room[i][j] = true;
            }
            else
                room[i][j] = false;
        }
    }
}