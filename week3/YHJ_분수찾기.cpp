#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int value;

int main()
{
	cin >> value;

	int it = 1;
	int remain = value - it;

	while (remain > it)
	{
		it++;
		remain -= it;
	}

	if (remain != 0)
		it++;
	else
		remain = it;

	int down = it - remain + 1;
	int up = remain;
	
	if (it % 2 == 1)
		cout << down << "/" << up;
	else
		cout << up << "/" << down;



	return 0;
}