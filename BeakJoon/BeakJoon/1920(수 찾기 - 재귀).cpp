#include <iostream>
#include <algorithm>

using namespace std;

int map[100'000];

bool BS(int s, int e, int v)
{
	if (s >= e)
	{
		return false;
	}

	int m = (s + e) / 2;

	if (map[m] == v)
	{
		return true;
	}
	
	else if (map[m] > v)
	{
		return BS(s, m, v);
	}

	else
	{
		return BS(m + 1, e, v);
	}
}


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

	std::sort(map, map + N);

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int num;
		cin >> num;

		cout << (BinarySearch(map, 0, N, num) ? "1\n" : "0\n");
	}


}