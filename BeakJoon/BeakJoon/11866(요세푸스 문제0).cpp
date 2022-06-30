#include <queue>
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

	queue<int> q;

	for (int i = 1; i <= N; ++i)
	{
		q.push(i);
	}


	int people;
	int killcount = 0;

	cout << "<";
	while (q.size() != 1)
	{

		people = q.front();
		++killcount;

		if (killcount != K)
		{
			q.pop();
			q.push(people);
		}

		else if (killcount == K)
		{
			killcount = 0;
			cout << people << ", ";
			q.pop();
		}
	}
	cout << q.front() << ">\n";

	return 0;
}