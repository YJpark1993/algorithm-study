#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
string input;
vector<string> result;

void Check(string _input, array<int, 20> brac, int i)
{
	if (i < 10 && brac[i] >= 0)
	{
		_input.replace(brac[i], 1, "a");
		_input.replace(brac[i + 1], 1, "a");

		string _temp = _input;
		_temp.erase(remove(_temp.begin(), _temp.end(), 'a'), _temp.end());

		//if (find(result.begin(), result.end(), _temp) == result.end())
			result.push_back(_temp);
		Check(_input, brac, i + 2);
	}
}

int main()
{
	cin >> input;

	array<int, 20> brac;
	array<int, 10> depth;

	int depth_cur = 0;
	int count = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			depth[depth_cur] = i;
			depth_cur++;
		}
		else if (input[i] == ')')
		{
			depth_cur--;
			brac[count] = depth[depth_cur];
			brac[count + 1] = i;
			count += 2;
			depth[depth_cur] = -1;
		}
	}

	for (int i = 0; i < 20; i += 2)
	{
		Check(input, brac, i);
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}