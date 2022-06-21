#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string set;
	cin >> set;

	list<char> editor;
	list<char>::iterator iter;

	for (int i = 0; i < set.length(); ++i)
	{
		editor.push_back(set[i]);
	}

	iter = editor.end();

	int N;
	cin >> N;

	char command;
	for (int i = 0; i < N; ++i)
	{
		cin >> command;

		switch (command)
		{
		case 'L':
			if (iter != editor.begin())
			{
				--iter;
			}
			break;

		case 'D':
			if (iter != editor.end())
			{
				++iter;
			}
			break;

		case 'B':
			if (iter != editor.begin())
			{
				iter = editor.erase(--iter);
			}
			break;

		case 'P':
			char insertChar;
			cin >> insertChar;
			editor.insert(iter, insertChar);
			break;
		}
	}
	for (iter = editor.begin(); iter != editor.end(); ++iter)
	{
		cout << *iter;
	}
	cout << "\n";

	return 0;

}