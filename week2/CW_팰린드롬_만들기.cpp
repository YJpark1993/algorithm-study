#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;

bool is_palindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main()
{
    cin >> str;
    string add_str = "";

    int index = 0;

    string copy_str = str;
    while (is_palindrome(copy_str) == false)
    {
        copy_str = str;
        add_str += str[index++];
        for (auto it = add_str.rbegin(); it != add_str.rend(); ++it)
        {
            copy_str += *it;
        }
    }

    cout << copy_str.length() << endl;

    return 0;
}
