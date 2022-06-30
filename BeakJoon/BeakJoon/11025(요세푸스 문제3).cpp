#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	int K;
	cin >> N >> K;

	int result = 0;

	for (int i = 1; i <= N; ++i)
	{
		result = (result + K) % i;
	}

	cout << result + 1;

	return 0;
}