#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int tomatoCase[1000][1000] = { 0 };
int N, moon;
int date;

queue <pair<int, int>> TOMATO;

int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };

void bfs()
{
	while (false == TOMATO.empty())
	{
		int tx = TOMATO.front().first;
		int ty = TOMATO.front().second;

		TOMATO.pop();

		for (int i = 0; i < 4; ++i)
		{
			int gx = tx + dx[i];
			int gy = ty + dy[i];

			if (gx >= 0 && gx < N && gy >= 0 && gy < moon)
			{
				if (tomatoCase[gx][gy] == 0)
				{
					tomatoCase[gx][gy] = tomatoCase[tx][ty] + 1;
					TOMATO.push({ gx, gy });
				}
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> moon >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < moon; ++j)
		{
			cin >> tomatoCase[i][j];

			if (tomatoCase[i][j] == 1)
			{
				TOMATO.push({ i, j });
			}
		}
	}

	bfs();
	
	int date = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < moon; ++j)
		{
			if (tomatoCase[i][j] == 0)
			{
				cout << "-1\n";
				return 0;
			}

			if (date < tomatoCase[i][j])
			{
				date = tomatoCase[i][j];
			}
		}
	}

	cout << date - 1 << "\n";

	return 0;
}