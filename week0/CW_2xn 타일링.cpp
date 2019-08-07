#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	std::cin >> n;

	long long d[1001];
	d[0] = 1;
	d[1] = 1;
	if (n >= 2)
	{
		for (int i = 2; i <= n; i++)
		{
			d[i] = (d[i - 1] + d[i - 2]) % 10007;
		}
	}

	std::cout << d[n];
	return 0;
}
