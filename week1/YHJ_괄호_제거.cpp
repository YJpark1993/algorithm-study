#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
string check_str;
vector<string> strs; // input strings
int str_in;          // input string counts
int left, right;     // search var

int search_lr(int left, int right, int search_idx);

bool cmp_length(const string &p1, const string &p2)
{
    if (p1.length() < p2.length())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int search_left(int left, int right, int search_idx)
{
    if (search_idx < strs.size())
    {
        string search_str = strs[search_idx];
        if (left == 0)
            return check_str.length();
        else
        {
            int _left = check_str.rfind(search_str, left - 1);
            if (_left == -1)
                return check_str.length();
            else
                return search_lr(_left, right, search_idx + 1);
        }
    }
    else
        return right - left;
    return check_str.length();
}
int search_right(int left, int right, int search_idx)
{
    if (search_idx < strs.size())
    {
        string search_str = strs[search_idx];
        if (right == check_str.length())
            return check_str.length();
        else
        {
            int _right = check_str.find(search_str, left);
            if (_right == -1)
                return check_str.length();
            else
            {
                _right = _right + search_str.length();
                _right = max(_right, right);
                return search_lr(left, _right, search_idx + 1);
            }
        }
    }
    else
        return right - left;
    return check_str.length();
}

int search_lr(int left, int right, int search_idx)
{
    int lcount = search_left(left, right, search_idx);
    int rcount = search_right(left, right, search_idx);
    return min(lcount, rcount);
}

int search()
{
    string search_str = strs[0];
    int pos = check_str.find(search_str, 0);
    if (pos == -1)
        return check_str.length();
    int _left = pos;
    int _right = pos + search_str.length();
    int result = search_lr(_left, _right, 1);

    while (pos != string::npos)
    {
        pos = check_str.find(search_str, pos + 1);
        if (pos != -1)
        {
            _left = pos;
            _right = pos + search_str.length();
            result = min(result, search_lr(_left, _right, 1));
        }
    }
    return result;
}

int main()
{
    cin >> str_in;
    for (int i = 0; i < str_in; i++)
    {
        string _temp;
        int _temp_i;
        cin >> _temp_i >> _temp;
        bool in_check = true;

        for (int j = 0; j < strs.size(); j++)
        {
            string str = strs[j];
            //cout << str << endl;
            if (_temp.length() <= str.length() && str.find(_temp) != string::npos)
            {
                in_check = false;
            }
            if (_temp.length() > str.length() && _temp.find(str) != string::npos)
            {
                in_check = false;
                strs[j] = _temp;
                //break;
            }
        }
        if (in_check)
            strs.push_back(_temp);
    }
    sort(strs.begin(), strs.end(), cmp_length);
    int t;
    cin >> t >> check_str;
    t = search();
    cout << t << endl;
    return 0;
}
