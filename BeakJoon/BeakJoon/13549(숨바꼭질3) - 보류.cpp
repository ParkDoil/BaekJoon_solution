#include <iostream>
#include <queue>

using namespace std;

int subin, dongsaengPos;
bool isVisited[100'001] = { false };


void bfs(int pos)
{
	queue<pair<int, int>> game;
	game.push({ pos, 0 });

	while (false == game.empty())
	{
		int subinPos = game.front().first;
		int time = game.front().second;


		game.pop();

		if (subinPos == dongsaengPos)
		{
			cout << time << "\n";
			break;
		}

		if (subinPos + 1 >= 0 && subinPos + 1 <= 100000)
		{
			if (false == isVisited[subinPos + 1])
			{
				isVisited[subinPos + 1] = true;
				game.push({ subinPos + 1,time + 1 });
			}
		}

		if (subinPos - 1 >= 0 && subinPos - 1 <= 100000)
		{
			if (false == isVisited[subinPos - 1])
			{
				isVisited[subinPos - 1] = true;
				game.push({ subinPos - 1,time + 1 });
			}
		}

		if (subinPos * 2 >= 0 && subinPos * 2 <= 100000)
		{
			if (false == isVisited[subinPos * 2])
			{
				isVisited[subinPos * 2] = true;
				game.push({ subinPos * 2,time });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> subin >> dongsaengPos;
	isVisited[subin] = true;

	bfs(subin);

	return 0;
}