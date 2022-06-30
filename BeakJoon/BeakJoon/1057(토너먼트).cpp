#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int player;
	double kim, im;
	cin >> player >> kim >> im;

	int round = 0;

	while (kim != im)
	{

		kim = std::round(kim / 2);
		im = std::round(im / 2);

		/*if (kim > 1)
		{
			if ((kim / 2 - (int)kim / 2) >= 0.5)
			{
				kim = (int)kim / 2 + 1;
			}
			else
			{
				kim = (int)kim / 2;
			}
		}

		if ( im > 1)
		{
			if ((im / 2 - (int)im / 2) >= 0.5)
			{
				im = (int)im / 2 + 1;
			}

			else
			{
				im = (int)im / 2;
			}
		}*/

		round++;
	}

	cout << round;

	return 0;
}