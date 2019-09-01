#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    int kg_5_num;
    int kg_3_num;
    int temp;

    kg_5_num = N / 5;
    temp = N % 5;
    kg_3_num = temp / 3;
    while (temp % 3 != 0)
    {
        kg_5_num -= 1;
        if (kg_5_num < 0)
        {
            std::cout << -1 << std::endl;
            return 0;
        }
        temp += 5;
        kg_3_num = temp / 3;
    }
    
    int result = kg_5_num + kg_3_num;
    if (result == 0)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << result << std::endl;
    }

    return 0;
}
