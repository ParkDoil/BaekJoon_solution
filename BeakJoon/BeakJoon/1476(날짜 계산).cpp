#include <iostream>

using namespace std;

int earth, solar, moon;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> earth >> solar >> moon;

	int result;

	int year = 1;

	while (1)
	{
		if ((year - earth) % 15 == 0 && (year - solar) % 28 == 0 && (year - moon) % 19 == 0)
		{
			result = year;
			break;
		}

		year++;
	}

	cout << result << "\n";

	return 0;

}