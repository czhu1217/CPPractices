
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int N;
vector<string> suf;
int lcpp(string s, string t)
{
    // cout << "lcp" << " " + s + " " + t;
    int n = min(s.size(), t.size());
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            // cout << i << "\n";
            return i;
        }
    }
    // cout << n << "\n";
    return n;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        suf.clear();
        string s;
        cin >> s;
        if(s.size()==0){
            cout << 0 << "\n";
            break;
        }
        for (int j = 0; j < s.size(); j++)
        {
            // cout << "loop";
            suf.push_back(s.substr(j));
            // cout << s.substr(j) + "\n";
        }
        sort(suf.begin(), suf.end());
        int cnt = suf.front().size();
        for(int i=1;i<suf.size();i++){
            // cout << "cnt " << cnt << "\n";
            int lcp = lcpp(suf.at(i), suf.at(i-1));
            cnt += suf.at(i).size() - lcp;
        }

        // for (std::vector<string>::iterator it = suf.begin() + 1; it != suf.end(); it++)
        // {
          
        //     int lcp = lcpp(*it, *(it - 1));
        //     string temp = *it;
        //     cnt += temp.size() - lcp;
        // }
        cout << cnt+1 << "\n";
    }
    return 0;
}
