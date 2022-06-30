#include <queue>
#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	queue<int> card;
	
	for (int i = 1; i <= N; ++i)
	{
		card.push(i);
	}


	while (card.size() != 1)
	{
		int cardnum;
		card.pop();
		cardnum = card.front();

		card.pop();
		card.push(cardnum);
	}

	cout << card.front() << "\n";

	return 0;
}