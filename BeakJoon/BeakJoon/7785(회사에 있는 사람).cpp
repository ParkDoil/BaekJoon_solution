#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using ll = long long;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, string> company;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string name;
		string inOut;
		cin >> name;
		cin >> inOut;

		if (inOut == "enter")
		{
			company.insert(pair<string, string>(name, name));
		}

		if (inOut == "leave")
		{
			company.erase(name);
		}
	}


	map<string, string>::reverse_iterator riter;


	for (riter = company.rbegin(); riter != company.rend(); ++riter)
	{
		cout << riter->first.c_str() << "\n";
	}

	return 0;
}