#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>


using namespace std;

int tomatoCase[100][100][100] = {0};
int N, moon, H;
int date;

queue <pair<pair<int, int>, int>> TOMATO;

int dx[] = { 0, 1, 0, -1, 0, 0 };
int dy[] = { -1, 0, 1, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

void bfs()
{
	while (false == TOMATO.empty())
	{
		int tx = TOMATO.front().first.first;
		int ty = TOMATO.front().first.second;
		int tz = TOMATO.front().second;

		TOMATO.pop();
		for (int i = 0; i < 6; ++i)
		{
			int gx = tx + dx[i];
			int gy = ty + dy[i];
			int gz = tz + dz[i];

			if (gx >= 0 && gx < N && gy >= 0 && gy < moon && gz >= 0 && gz < H)
			{
				if (tomatoCase[gx][gy][gz] == 0)
				{
					tomatoCase[gx][gy][gz] = tomatoCase[tx][ty][tz] + 1;
					TOMATO.push({ { gx, gy }, gz });
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

	cin >> moon >> N >> H;

	for (int h = 0; h < H; ++h)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < moon; ++j)
			{
				cin >> tomatoCase[i][j][h];

				if (tomatoCase[i][j][h] == 1)
				{
					TOMATO.push({ { i, j }, h });
				}
			}
		}
	}

	bfs();

	int date = 0;

	for (int h = 0; h < H; ++h)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < moon; ++j)
			{
				if (tomatoCase[i][j][h] == 0)
				{
					cout << "-1\n";
					return 0;
				}

				if (date < tomatoCase[i][j][h])
				{
					date = tomatoCase[i][j][h];
				}
			}
		}
	}

	cout << date - 1 << "\n";

	return 0;
}