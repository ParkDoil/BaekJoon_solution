#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[8][8];
int X[8], Y[8];
int tempX[8], tempY[8];
int newMap[8][8];
int nextX[8], nextY[8];
int result[8][8];

int moon, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> moon >> K;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> map[i][j];
			map[i][j] -= moon;
			Y[i] += map[i][j];
			X[j] += map[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((Y[i] + X[j] - map[i][j]) % 2)
			{
				result[i][j] = 1;
				tempY[i]++;
				tempX[j]++;
			}
		}
	}
		

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			newMap[i][j] = tempY[i] + tempX[j] - result[i][j];
				nextY[i] += newMap[i][j];
				nextX[j] += newMap[i][j];
		}
	}
		

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int cur = nextY[i] + nextX[j] - newMap[i][j];

				if (result[i][j] && abs(Y[i] + X[j] - map[i][j] - cur) % 4 == 2)
				{
					result[i][j] = -1;
				}

		}
	}
		

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (result[i][j] == 1) cout << "+ ";
			else if (result[i][j] == 0) cout << ". ";
			else cout << "- ";
		}

		cout << '\n';
	}
	return 0;
}