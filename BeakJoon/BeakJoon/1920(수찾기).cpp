#include <iostream>
#include <algorithm>

using namespace std;

int map[100'000];


int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	std::sort(&map[0], &map[N]);

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int num;
		cin >> num;

		bool isExist = false;
		int s = 0;
		int e = N;
		while (s < e)
		{
			int m = (s + e) / 2;

			if (map[m] == num)
			{
				isExist = true;

				break;
			}

			else if (map[m] < num)
			{
				s = m + 1;
			}

			else
			{
				e = m;
			}
		}

		cout << (isExist ? "1\n" : "0\n");
	}


}