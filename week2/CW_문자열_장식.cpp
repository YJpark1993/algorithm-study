#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <algorithm>

using namespace std;

int n;
set<string> p;
string s;

int s_min = std::numeric_limits<int>::max();
int s_max = 0;

bool find_min_max(string s, string str)
{
    int min = s.find(str);
    int max = s.rfind(str) + str.length();

    if (min < 0)
    {
        return false;
    }

    if (min < s_min)
    {
        s_min = min;
    }

    if (max > s_max)
    {
        s_max = max;
    }

    return true;
}

int main()
{
    string temp;
    int tnum;
    int length = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tnum >> temp;
        if (length < tnum)
        {
            length = tnum;
        }
        p.insert(temp);
    }

    cin >> tnum >> s;
    int s_length = tnum;

    for (auto it = p.begin(); it != p.end(); ++it)
    {
        find_min_max(s, *it);
    }

    string dest;
    bool flag = false;
    int size;
    for (size = length; size <= s_length; size++)
    {
        for (int cur = s_min; cur <= s_max - size; cur++)
        {
            dest = s.substr(cur, size);
            for (auto it = p.begin(); it != p.end(); ++it)
            {
                if (dest.find(*it) == string::npos)
                {
                    flag = false;
                    break;
                }
                flag = true;
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    cout << size << endl;

    return 0;
}
