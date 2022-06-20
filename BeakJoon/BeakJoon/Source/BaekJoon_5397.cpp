#include <iostream>
#include <list>
#include <string>

using namespace std;



int main()
{
	int N;
	cin >> N;

	list<char> password;
	list<char>::iterator iter;
	string inputKey;

	for (int test = 0; test < N; ++test)
	{
		getline(cin, inputKey);
		
		password.clear();

		iter = password.begin();

		for (int i = 0; i < inputKey.length(); ++i)
		{
			switch (inputKey[i])
			{
			case '<':
				if (iter != password.begin())
				{
					--iter;
				}
				break;

			case '>':
				if (iter != password.end())
				{
					++iter;
				}
				break;

			case '-':
				if (iter != password.begin())
				{
					iter = password.erase(--iter);
				}
				break;

			default:
				password.insert(iter, inputKey[i]);
				break;
			}
		}

		for (iter = password.begin(); iter != password.end(); ++iter)
		{
			cout << *iter;
		}
		cout << "\n";

	}
	
	return 0;
}