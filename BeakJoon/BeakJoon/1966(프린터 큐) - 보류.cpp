#include <queue>
#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	queue<int> docuName;
	queue<int> importance;
	queue<int> checkimport;

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int N;
		int M;
		int import;
		int maximport = 0;
		cin >> N >> M;

		for (int j = 0; j < N; ++j)
		{
			cin >> import;
			docuName.push(j);
			importance.push(import);
		}

		checkimport = importance;


	}

	return 0;
}