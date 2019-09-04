#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
int input;

int main()
{
	cin >> input;

	int margin = input;
	int count = input / 5;
	int count_3 = 0;

	while (count >= 0)
	{
		int remain = margin - count * 5;
		if (remain % 3 == 0)
		{
			count_3 = remain / 3;
			break;
		}
		count--;
	}

	if (count == 0 && count_3 == 0)
		cout << -1;
	else
		cout << count + count_3;
	return 0;
}