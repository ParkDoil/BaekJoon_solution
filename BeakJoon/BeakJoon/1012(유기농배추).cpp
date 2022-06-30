#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int field[50][50] = { 0 };
bool isVisited[50][50] = { false };
int px[] = { -1, 0, 1, 0 }, py[] = { 0, 1, 0, -1 };


void dfs(int x, int y, int inputX, int inputY)
{
	isVisited[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int gx = x + px[i];
		int gy = y + py[i];

		if (gx < 0 || gy < 0 || gx >= inputX || gy >= inputY)
		{
			continue;
		}

		if (field[gx][gy] == 1 && false == isVisited[gx][gy])
		{
			dfs(gx, gy, inputX, inputY);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase, xLength, yLength, cabbageCount;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int needbug = 0;

		memset(field, 0, sizeof(field));
		memset(isVisited, false, sizeof(isVisited));

		cin >> xLength >> yLength >> cabbageCount;

		for (int j = 0; j < cabbageCount; ++j)
		{
			int cabbageX, cabbageY;
			cin >> cabbageX >> cabbageY;

			field[cabbageX][cabbageY] = 1;
		}

		for (int i = 0; i < xLength; ++i)
		{
			for (int j = 0; j < yLength; ++j)
			{
				if (field[i][j] == 1 && false == isVisited[i][j])
				{

					dfs(i, j, xLength, yLength);

					++needbug;
				}
			}
		}

		cout << needbug << "\n";

	}

	return 0;
}