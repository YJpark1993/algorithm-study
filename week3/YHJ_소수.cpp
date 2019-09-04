#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int min_value;
int max_value;
vector<int> primes;
vector<int> result_primes;

bool check_prime(int c_value)
{
	for (int i = 0; i < primes.size(); i++)
	{
		int prime = primes[i];
		if (c_value % prime == 0)
			return false;
	}
	primes.push_back(c_value);
	return true;
}

int main()
{
	cin >> min_value;
	cin >> max_value;

	int it = 2;

	while (it < min_value)
	{
		check_prime(it);
		it++;
	}

	while (it <= max_value)
	{
		if (check_prime(it))
		{
			result_primes.push_back(it);
		}
		it++;
	}

	if (result_primes.size() > 0)
	{
		int first_prime = result_primes[0];
		int sum_value = 0;
		for (std::vector<int>::iterator it = result_primes.begin(); it != result_primes.end(); ++it)
			sum_value += *it;

		cout << sum_value << endl;
		cout << first_prime << endl;
	}
	else
	{
		cout << -1;
	}


	return 0;
}