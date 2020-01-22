#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int N, K, cnt;
bool nl = false;
string s;
int main()
{
    ifstream fin("word.in");
    ofstream fout("word.out");

    fin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        fin >> s;
        nl = false;
        if (i == 0)
        {
            fout << s;
            cnt += s.size();
            continue;
        }
        if (cnt + s.size()> K)
        {
            nl = true;
        }
        if (nl)
        {
            fout << "\n";
            fout << s;
            cnt = s.size();
        }
        else
        {
            cnt += s.size();
            fout << " " + s;

        }
    }
    return 0;
}