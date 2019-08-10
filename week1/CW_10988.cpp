#include <iostream>
#include <cstring>

using namespace std;

int check_palindrome(char* word)
{
    int length = strlen(word);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        if (word[start] != word[end])
        {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

int main()
{
    char word[101];
    cin >> word;

    int result = check_palindrome(word);
    cout << result << endl;

    return 0;
}
