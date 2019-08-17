#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<string> p;
char s[500000];

string get_str(const char* start, int size)
{
    string result = "";
    for (int i = 0; i < size; i++)
    {
        result += start[i];
    }

    return result;
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
        p.push_back(temp);
    }

    cin >> tnum >> s;
    int s_length = tnum;

    string dest;
    bool flag = false;
    for (int size = length; size <= s_length; size++)
    {
        for (int cur = 0; cur <= s_length - size; cur++)
        {
            dest = get_str(s + cur, size);
            for (size_t i = 0; i < p.size(); i++)
            {
                if (dest.find(p[i]) == string::npos)
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

    cout << dest.size() << endl;

    return 0;
}
