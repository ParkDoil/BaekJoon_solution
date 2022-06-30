#include <deque>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> dq;

	for (int i = 0; i < N; ++i)
	{
		int element;
		string commend;
		cin >> commend;

		if (commend == "push_front")
		{
			cin >> element;
			dq.push_front(element);
		}

		else if (commend == "push_back")
		{
			cin >> element;
			dq.push_back(element);
		}

		else if (commend == "pop_front")
		{
			if (dq.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}

		else if (commend == "pop_back")
		{
			if (dq.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		
		else if (commend == "size")
		{
			cout << dq.size() << "\n";
		}

		else if (commend == "empty")
		{
			if (dq.empty())
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
			if (dq.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dq.front() << "\n";
			}
		}

		else if (commend == "back")
		{
			if (dq.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << dq.back() << "\n";
			}
		}

	}

	return 0;
}