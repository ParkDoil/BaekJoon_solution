#include <string>
#include <iostream>
#include <map>

using namespace std;

string dogam[100'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int> dogamMap;

	int poketmonN, solutionM;

	cin >> poketmonN >> solutionM;

	for (int i = 1; i <= poketmonN; ++i)
	{
		cin >> dogam[i];
		dogamMap[dogam[i]] = i;
	}

	for (int i = 0; i < solutionM; ++i)
	{
		string question;
		cin >> question;


		if (question[0] >= '1' && question[0] <= '9')
		{
			int ifInt = stoi(question);
			cout << dogam[ifInt] << "\n";
		}
		else
		{
			cout << dogamMap[question] << "\n";
		}
	}


	return 0;
}