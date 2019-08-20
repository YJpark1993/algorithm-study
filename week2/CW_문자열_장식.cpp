#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> p;
string s;

int s_min = std::numeric_limits<int>::max();
int s_max = 0;

void find_min_max(string str)
{
    int min = s.find(str);
    if (min < s_min)
    {
        s_min = min;
    }

    int max = s.rfind(str);
    if (max > s_max)
    {
        s_max = max;
    }
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

    sort(p.begin(), p.end(), [](string x, string y) {
                return x > y;
            });

    for (auto it = p.begin(); it != p.end(); ++it)
    {
        find_min_max(*it);
    }

    string dest;
    bool flag = false;
    int min_size, max_size;
    for (int size = length; size <= s_length; size++)
    {
        dest = s.substr(s_min, size);
        for (size_t i = 0; i < p.size(); i++)
        {
            if (dest.find(p[i]) == string::npos)
            {
                flag = false;
                break;
            }
            flag = true;
            min_size = size;
        }
        if (flag)
        {
            break;
        }
    }
    int i = 0;
    for (int size = length; size <= s_length; size++, i++)
    {
        dest = s.substr(s_max - i, size);
        for (size_t i = 0; i < p.size(); i++)
        {
            if (dest.find(p[i]) == string::npos)
            {
                flag = false;
                break;
            }
            flag = true;
            max_size = size;
        }
        if (flag)
        {
            break;
        }
    }

    int result = min_size > max_size ? max_size : min_size;

    cout << result << endl;

    return 0;
}
