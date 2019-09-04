#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string oper;
int bracket[10][2];
set<string> results;

string get_oper(const string oper)
{
    string result = "";
    for (int i = 0; i < int(oper.size()); i++)
    {
        if (oper[i] == 'a')
        {
            continue;
        }
        result += oper[i];
    }
    return result;
}

void print_recursive(string oper, int index, int start)
{
    if (start >= index)
    {
        return;
    }
    oper[bracket[start][0]] = 'a';
    oper[bracket[start][1]] = 'a';

    for (int i = 1; i < index - start; i++)
    {
        print_recursive(oper, index, start + i);
    }
}

int main()
{
    stack<int> stk;
    
    getline(cin, oper);


    int index = 0;
    int size = int(oper.size());
    for (int i = 0; i < size; i++)
    {
        if (oper[i] == '(')
        {
            stk.push(i);
        }

        if (oper[i] == ')')
        {
            bracket[index][0] = stk.top();
            bracket[index++][1] = i;
            stk.pop();
        }
    }

    for (int i = 0; i < index; i++)
    {
        print_recursive(oper, index, i);
    }
    //sort(results.begin(), results.end());

    for (auto it = results.begin(); it != results.end(); it++)
    {
      cout << *it << endl;
    }

    return 0;
}
