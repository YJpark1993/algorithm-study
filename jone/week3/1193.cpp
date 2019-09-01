#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int first = 1;
    int second = 1;
    int direction = 1;

    for (int i = 1; i < n; i++)
    {
        // 분자가 1일 때
        if (first == 1)
        {
            // 분모가 짝수면
            if (second % 2 == 0)
            {
                first += 1;
                second -= 1;
                direction = 0;
            }
            else
            {
                second += 1;
            }
        }
        // 분모가 1일 때
        else if (second == 1)
        {
            // 분자가 짝수면
            if (first % 2 == 0)
            {
                first += 1;
            }
            else
            {
                first -= 1;
                second += 1;
                direction = 1;
            }
        }
        else
        {
            if (direction == 1)
            {
                second += 1;
                first -= 1;
            }
            else
            {
                second -= 1;
                first += 1;
            }
        }

    }

    std::cout << first << "/" << second << std::endl;

    return 0;
}
