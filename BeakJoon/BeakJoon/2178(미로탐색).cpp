#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int N, moon;

int map[100][100];
int moving[100][100] = { 0 };
bool isVisited[100][100] = { false };


int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y)
{

	isVisited[x][y] = true;
	++moving[x][y];

	queue<pair<int, int>> Q;

	Q.push({ x, y });

	while (Q.empty() == false)
	{
		int tx = Q.front().first;
		int ty = Q.front().second;

		Q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int gx = tx + dx[i];
			int gy = ty + dy[i];
			
			if (gx < 0 || gx >= N || gy < 0 || gy >= moon)
			{
				continue;
			}

			else
			{
				if (false == isVisited[gx][gy] && map[gx][gy] == 1)
				{
					isVisited[gx][gy] = true;
					Q.push({ gx, gy });
					moving[gx][gy] = moving[tx][ty] + 1;
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

	cin >> N >> moon;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < moon; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	bfs(0, 0);

	cout << moving[N - 1][moon - 1] << "\n";

	return 0;
}