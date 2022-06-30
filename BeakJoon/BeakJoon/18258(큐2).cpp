#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	queue<int> myq;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string commend;
		cin >> commend;
		if (commend == "push")
		{
			int element;
			cin >> element;
			myq.push(element);
		}

		else if (commend == "pop")
		{
			if (myq.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << myq.front() << "\n";
				myq.pop();
			}
		}

		else if (commend == "size")
		{
			cout << myq.size() << "\n";
		}

		else if (commend == "empty")
		{
			if (myq.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}

		else if (commend == "front")
		{
			if (myq.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << myq.front() << "\n";
			}
		}

		else if (commend == "back")
		{
			if (myq.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << myq.back() << "\n";
			}
		}
	}

	return 0;
}