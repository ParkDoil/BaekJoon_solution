#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int needsPeople;
	int cityCount;

	cin >> needsPeople >> cityCount;

	int pay[20];
	int people[20];
	double efficiency[20];
	
	double maxEfficiency;
	int bestIndex = 0;
	int cheap;
	int cheapIndex = 0;

	for (int i = 0; i < cityCount; ++i)
	{
		cin >> pay[i] >> people[i];
		efficiency[i] = (double)people[i] / (double)pay[i];
		
		if (i == 0)
		{
			cheap = pay[i];
			maxEfficiency = efficiency[i];
		}

		else if (i > 0)
		{
			if (cheap > pay[i])
			{
				cheap = pay[i];
				cheapIndex = i;
			}

			if (maxEfficiency < efficiency[i])
			{
				maxEfficiency = efficiency[i];
				bestIndex = i;
			}
		}
	}

	int result = 0;
	int process = needsPeople / people[bestIndex];
	int remain = needsPeople - (process * people[bestIndex]);

	for (int i = 0; i < process; ++i)
	{
		result += pay[bestIndex];
	}

	while (remain > 0)
	{
		result += pay[cheapIndex];
		remain -= people[cheapIndex];
	}

	cout << result;

	return 0;
  }