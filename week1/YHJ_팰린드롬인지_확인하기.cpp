#include <iostream>
#include <string>

using namespace std;
string input;

int main()
{
	cin >> input;
	int length = input.length();
	for (int i = 0; i <= length / 2; i++)
	{
		if (input[i] == input[length - i - 1])
		{
			// ok
		}
		else
		{
			cout << "0";
			return 0;
		}
	}

	cout << "1";
	return 0;
}