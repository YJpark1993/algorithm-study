#include <climits>
#include <iostream>

const int BOARD_SIZE = 8;

char changeColor(char color)
{
	return (color == 'W') ? 'B' : 'W';
}

int getToChange(int startRow, int startCol, char arr[][51])
{
	char color1 = 'W';
	char color2 = 'B';
	int count1 = 0;
	int count2 = 0;
	for (int i = startRow; i < startRow + BOARD_SIZE; i++)
	{
		for (int j = startCol; j < startCol + BOARD_SIZE; j++)
		{
			if (j == startCol)
			{
				if (color1 != arr[i][j])
				{
					count1++;
				}
				if (color2 != arr[i][j])
				{
					count2++;
				}
			}
			else
			{
				color1 = changeColor(color1);
				color2 = changeColor(color2);
				if (color1 != arr[i][j])
				{
					count1++;
				}
				if (color2 != arr[i][j])
				{
					count2++;
				}
			}
		}
	}
	return count1 > count2 ? count2 : count1;
}

int main(void)
{
    std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int row, col;
	std::cin >> row >> col;

	if (row < 8 || col < 8)
	{
		std::cout << "입력값이 작습니다.\n";
		return -1;
	}

	char mnArray[50][51];

	// 입력
	for (int i = 0; i < row; i++)
	{
		std::cin >> mnArray[i];
	}

	int rowNum = row - BOARD_SIZE + 1;
	int colNum = col - BOARD_SIZE + 1;

	int temp;
	int result = INT_MAX;
	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			temp = getToChange(i, j, mnArray);
			if (temp < result)
			{
				result = temp;
			}
		}
	}

    std::cout << result;
	return 0;
}
