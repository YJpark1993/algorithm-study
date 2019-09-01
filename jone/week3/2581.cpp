#include <iostream>
#include <vector>

bool is_prime(int num, const std::vector<int>& nums)
{
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        if (num % *it == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int M, N;
    std::cin >> M >> N;
    
    // 에라토스테네스의 체
    std::vector<int> nums;
    std::vector<int> results;

    for (int i = 2; i <= N; i++)
    {
        // 해당 숫자가 소수면
        if (is_prime(i, nums))
        {
            nums.push_back(i);
            // 소수인 숫자가 해당 범위에 있으면
            if (i >= M && i <= N)
            {
                results.push_back(i);
            }
        }
    }

    int sum = 0;
    if (results.size() == 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    for (auto it = results.begin(); it != results.end(); ++it)
    {
        sum += *it;
    }

    std::cout << sum << std::endl;
    std::cout << results[0] << std::endl;

    return 0;
}
