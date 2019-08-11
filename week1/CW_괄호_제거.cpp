#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string oper;
int flag[200];
int bracket[10][2];
vector<string> results;

string print_str(int size)
{
    string result = "";
    for (int i = 0; i < size; i++)
    {
        if (flag[i] == 1)
        {
            continue;
        }
        //cout << oper[i];
        result += oper[i];
    }
    //cout << endl;
    return result;
}

void print_recursive(int size, int index, int depth, int start)
{
    memset(flag, 0, sizeof(flag));
    if (depth <= 0)
    {
        return;
    }
    if (start >= index)
    {
        return;
    }

    for (int i = 0; i < index; i++)
    {
        print_recursive(size, index, depth - 1, start + i);
    }

    flag[bracket[start][0]] = 1;
    flag[bracket[start][1]] = 1;
    
    results.push_back(print_str(size));
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

    print_recursive(size, index, index, 0);
    sort(results.begin(), results.end());

    for (size_t i = 0; i < results.size(); i++)
    {
      cout << results[i] << endl;
    }

    return 0;
}
