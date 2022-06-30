#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int student[31] = { 0 };

	for (int i = 0; i < 28; ++i)
	{
		int subjectID;
		cin >> subjectID;
		student[subjectID] = 1;
	}

	for (int i = 1; i <= 30; ++i)
	{
		if (student[i] == 0)
		{
			cout << i << "\n";
		}
	}

	return 0;
}